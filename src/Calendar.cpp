
#include "Calendar.hpp"
#include "utility"

#include <algorithm>
#include <stdexcept>
#include <regex>

auto Calendar::findSchedule(User::Group group) const {
    return schedules_.equal_range(group);
}

auto Calendar::findLesson(const std::pair<Calendar::Schedules::const_iterator, 
                                          Calendar::Schedules::const_iterator>& range,
                          const std::string& date,
                          const std::string& time) const
{
    auto prediction = [&date, &time](const auto& element) {
       return !element.second.getDate().compare(date) && !element.second.getTime().compare(time);
    };
    return std::find_if(range.first, range.second, prediction);
}

bool Calendar::isOfFormat(std::string str, std::string format) const
{
    std::regex match(format);
    return std::regex_match(str, match);
}

void Calendar::validateDate(std::string date) const
{
    if(!isOfFormat(date, "^[0-9]{4}" 
                         "[-]"
                         "(0[0-9]{1}|1[0-2]{1})"
                         "[-]"
                         "(0[0-9]{1}|1[0-9]{1}|2[0-9]{1}|3[0-1]{1})$")) 
    {
        throw std::invalid_argument("invalid date format.\n"
                                    "Valid formats are \"yyyy-mm-dd\"\n"
                                    "valid separetor \"-\"");
    }
}

void Calendar::validateTime(std::string time) const
{
    if(!isOfFormat(time, "(^0[0-9]|^1[0-9]{1}|^2[0-4]{1})"
                         "[:]"
                         "(0[0-9]{1}|[1-5]{1}[0-9]{1})$"))
    {
        throw std::invalid_argument("invalid time.\n"
                                    "Valid format is \"hh:mm\"\n");
    }
}

void Calendar::addLesson(User::Group group, 
                         const std::string& date, 
                         const std::string& time, 
                         const std::string& subject) 
{

    validateDate(date);
    validateTime(time);

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

const Lesson& Calendar::getLesson(User::Group group, 
                                   const std::string& date, 
                                   const std::string& time) const
{
    validateDate(date);
    validateTime(time);

    const auto& schedule = findSchedule(group);

    auto lesson = findLesson(schedule, date, time);
    if(lesson == schedules_.end()) {
        throw std::invalid_argument("lesson on day " + date + " and time " + time + " not found");
    }
    return lesson->second;
}

Calendar::Schedules Calendar::getSchedule(User::Group group)
{
    if(User::Group::ALL == group) {
        return schedules_;
    }
    
    auto schedule = findSchedule(group);
    
    Schedules selectedSchedule;
    std::copy(schedule.first, 
              schedule.second, 
              std::inserter(selectedSchedule, selectedSchedule.begin()));

    return selectedSchedule;
}
