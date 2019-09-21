#include "Attendance.hpp"

const std::string& Attendance::getEmail() const
{
    return email_;
}

const std::string& Attendance::getName() const
{
    return name_;
}

const std::string& Attendance::getAction() const
{
    return action_;
}

const std::string& Attendance::getComment() const
{
    return comment_;
}
    