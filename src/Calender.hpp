#pragma once

#include <unordered_map>
#include "Lesson.hpp"
#include "User.hpp"



class Calender
{
public:
    using  Schedules = std::unordered_multimap<User::Group, Lesson>;

private:
    auto findSchedule(User::Group group) const;

    auto findLesson(const std::pair<Calender::Schedules::const_iterator, 
                          Calender::Schedules::const_iterator>& range,
                    const std::string& date,
                    const std::string& time) const;

    void validateDate(const std::string& date);
    void validateTime(const std::string& time);

    Schedules schedules_;
public:
    Calender() = default;
    ~Calender() = default;

    void addLesson(User::Group group,
                   const std::string& date,
                   const std::string& time,
                   const std::string& subject);

    const Lesson& viewLesson(User::Group group, 
                             const std::string& date, 
                             const std::string& time) const;

    Calender::Schedules viewSchedule(User::Group group);
    
};
