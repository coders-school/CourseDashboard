#pragma once
#include "User.hpp"
#include <vector>
#include "UserHandler.hpp"
#include "Calender.hpp"
#include "AttendanceHandler.hpp"

class CourseDashboard
{
public:

    void loadFromFile(const std::string& pathTofile);
    void saveToFile(const std::string& pathTofile);

    bool login(const std::string& email, const std::string& password);

    Calender::Schedules viewSchedule(const std::string& email);

    void reportAbsence(const std::string& email, 
                       const std::string& date, 
                       const std::string& time, 
                       const std::string& comment);

    void reportMakeUp(const std::string& email, 
                      const std::string& date, 
                      const std::string& time,
                      const std::string& absentDate,
                      const std::string& comment);

    AttendanceHandler::AttendanceList viewAttendance(const std::string& email);

private:
    const User& findUserByEmail(const std::string& email);

    UserHandler userHandler_;
    Calender calender_;
    AttendanceHandler attendanceHandler_;
};
