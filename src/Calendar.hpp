#pragma once

#include <unordered_map>
#include "Lesson.hpp"
#include "User.hpp"


class Calendar
{
public:
    using  Schedules = std::unordered_multimap<User::Group, Lesson>;

    Calendar() = default;
    ~Calendar() = default;

private:
    auto findSchedule(User::Group group) const;

    auto findLesson(const std::pair<Calendar::Schedules::const_iterator, 
                          Calendar::Schedules::const_iterator>& range,
                    const std::string& date,
                    const std::string& time) const;


    bool isOfFormat(std::string str, std::string format) const;

    void validateDate(std::string date) const;
    void validateTime(std::string time) const;

    Schedules schedules_;

public:

    void addLesson(User::Group group,
                   const std::string& date,
                   const std::string& time,
                   const std::string& subject);

    const Lesson& getLesson(User::Group group, 
                             const std::string& date, 
                             const std::string& time) const;

    Calendar::Schedules getSchedule(User::Group group);
    
};
