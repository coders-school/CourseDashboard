
#include "Lesson.hpp"
#include <regex>
#include <stdexcept>

Lesson::Lesson(const std::string& data,
               const std::string& time, 
               const std::string& subject) 
               : 
               data_(data),
               time_(time), 
               subject_(subject)
{}

const std::string& Lesson::getData() const {
    return data_;
}

const std::string& Lesson::getTime() const {
    return time_;
}

const std::string& Lesson::getSubject() const {
    return subject_;
}
