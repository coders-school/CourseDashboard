
#include "Calender.hpp"
#include "utility"

#include <algorithm>
#include <stdexcept>
#include <regex>

auto Calender::findSchedule(User::Group group) const {
    return schedules_.equal_range(group);
}

auto Calender::findLesson(const std::pair<Calender::Schedules::const_iterator, 
                            Calender::Schedules::const_iterator>& range,
                          const std::string& date,
                          const std::string& time) const
{
    auto prediction = [&date, &time](const auto& element)
    {
       return !element.second.getDate().compare(date) && !element.second.getTime().compare(time);
    };
    return std::find_if(range.first, range.second, prediction);
}

void Calender::validateDateTime(const std::string& date, const std::string& time)
{
    std::regex dataMatch("[0-9]{2}[-|.|/][0-9]{2}[-|.|/][0-9]{4}|"
                         "[0-9]{4}[-|.|/][0-9]{2}[-|.|/][0-9]{2}|");

    if(!std::regex_match(date, dataMatch)) {
        throw std::invalid_argument("invalid date format.\n"
                                    "Valid formats are \"dd-mm-yyyy\" or \"yyyy-mm-dd\"\n"
                                    "valid separetor \".\" \"-\" \"\\\"");
    }

    std::regex timeMatch("[0-9]{2}[:][0-9]{2}");

    if(!std::regex_match(time, timeMatch)) {
        throw std::invalid_argument("invalid time format.\n"
                                    "Valid format is \"hh:mm\"\n");
    }
}

void Calender::addLesson(User::Group group, 
                         const std::string& date, 
                         const std::string& time, 
                         const std::string& subject) 
{
    validateDateTime(date, time);

    const auto& schedule = findSchedule(group);
    if(schedule.first != schedules_.end())
    {
        auto lesson = findLesson(schedule, date, time);
        if(lesson != schedule.second) {
            throw std::invalid_argument("There is available lesson on day " + date + " " + time);
        }
    }
    schedules_.emplace(group, Lesson(date, time, subject));
}

void Calender::eraseLesson(User::Group group, const std::string& date, const std::string& time)
{
    const auto& schedule = findSchedule(group);
    auto lesson = findLesson(schedule, date, time);
    if(lesson == schedules_.end()) {
        throw std::invalid_argument("lesson on day " + date + " and time " + time + " not found");
    }

    schedules_.erase(lesson);
}

const Lesson& Calender::viewLesson(User::Group group, const std::string& date, const std::string& time) const
{
    const auto& schedule = findSchedule(group);
    auto lesson = findLesson(schedule, date, time);
    if(lesson == schedules_.end()) {
        throw std::invalid_argument("lesson on day " + date + " and time " + time + " not found");
    }
    return lesson->second;
}

Calender::Schedules Calender::viewSchedule(User::Group group)
{
    if(User::Group::ALL == group) {
        return schedules_;
    }
    std::pair<Schedules::iterator, Schedules::iterator> schedule = schedules_.equal_range(group);
    
    Schedules selectedSchedule;
    std::copy(schedule.first, schedule.second, std::inserter(selectedSchedule, selectedSchedule.begin()));

    return selectedSchedule;
}
