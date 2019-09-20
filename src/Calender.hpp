#pragma once

#include <unordered_map>
#include "Lesson.hpp"



class Calender
{
public:
    using  Schedules = std::unordered_multimap<std::string, Lesson>;

private:
    auto findSchedule(const std::string& group) const;

    auto findLesson(const std::pair<Calender::Schedules::const_iterator, 
                      Calender::Schedules::const_iterator>& range,
                    const std::string& date,
                    const std::string& time) const;

    Schedules schedules_;
public:
    
    Calender() = default;
    ~Calender() = default;

    void addLesson(const std::string& group,
                   const std::string& date,
                   const std::string& time,
                   const std::string& subject);

    void eraseLesson(const std::string& group, const std::string& date, const std::string& time);

    const Lesson& viewLesson(const std::string& group, const std::string& date, const std::string& time) const;

    Calender::Schedules viewSchedule(const std::string& group);
    
};
