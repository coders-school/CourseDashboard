#pragma once

#include <string>

class Attendance
{
private:
    std::string email_;
    std::string name_;
    std::string action_;
    std::string comment_;

public:
    Attendance(const std::string& email,
               const std::string& name,
               const std::string& action,
               const std::string& comment)
               :
               email_(email),
               name_(name),
               action_(action),
               comment_(comment)
    {}

    ~Attendance() = default;

    const std::string& getEmail() const;
    const std::string& getName() const;
    const std::string& getAction() const;
    const std::string& getComment() const;
};

