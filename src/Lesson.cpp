
#include "Lesson.hpp"
#include <regex>
#include <stdexcept>

Lesson::Lesson(const std::string& date,
               const std::string& time, 
               const std::string& subject) 
               : 
               date_(date),
               time_(time), 
               subject_(subject)
{}

const std::string& Lesson::getDate() const {
    return date_;
}

const std::string& Lesson::getTime() const {
    return time_;
}

const std::string& Lesson::getSubject() const {
    return subject_;
}
