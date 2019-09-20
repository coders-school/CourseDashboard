#pragma once

#include <string>

class Lesson
{
    std::string data_;
    std::string time_;
    std::string subject_;

public:
    Lesson(const std::string& data, const std::string& time,  const std::string& subject);
    ~Lesson() {}

    const std::string& getData() const;
    const std::string& getTime() const;
    const std::string& getSubject() const;

    Lesson& operator=(const Lesson&) = default;
};
