#include "CourseDashboard.hpp"
#include "FileHandler.hpp"
#include "Utility.hpp"
#include "AuthenticationProvider.hpp"


void CourseDashboard::loadFromFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userFromFile = fileHandler.read();
    userHandler_.getUserDatabase()  = convertToArray(userFromFile);
}

void CourseDashboard::saveToFile(const std::string& pathTofile)
{
    FileHandler fileHandler(pathTofile);
    auto userVectorInJsonFormat = convertToJson(userHandler_.getUserDatabase());
    fileHandler.write(userVectorInJsonFormat.dump());
}

bool CourseDashboard::login(const std::string& email, const std::string& password)
{
    auto user = findUserByEmail(email);
    AuthenticationProvider authenticationProvider;

    return authenticationProvider(user, email, password);
}

Calender::Schedules CourseDashboard::viewSchedule(const std::string& email)
{
    if(!email.compare("")) {
        return calender_.viewSchedule(User::Group::ALL);
    }

    auto user = findUserByEmail(email);
    return calender_.viewSchedule(user.getGroup());
}

void CourseDashboard::reportAbsence(const std::string& email, 
                                    const std::string& date, 
                                    const std::string& time, 
                                    const std::string& comment)
{
    auto user = findUserByEmail(email);
    auto lesson = calender_.viewLesson(user.getGroup(), date, time);

    attendanceHandler_.reportAbsence(user, lesson, comment);
}

void CourseDashboard::reportMakeUp(const std::string& email, 
                                   const std::string& date, 
                                   const std::string& time,
                                   const std::string& absentDate,
                                   const std::string& comment)
{
    auto user = findUserByEmail(email);
    auto lesson = calender_.viewLesson(user.getGroup(), date, time);
    
    attendanceHandler_.reportMakeUp(user, lesson, absentDate,  comment);
}

AttendanceHandler::AttendanceList CourseDashboard::viewAttendance(const std::string& email)
{
    if(!email.compare("")) {
        return attendanceHandler_.viewReports(nullptr);
    }

    auto user = findUserByEmail(email);
    return attendanceHandler_.viewReports(&user);
}


const User& CourseDashboard::findUserByEmail(const std::string& email)
{
    auto byEmail = [&email](auto user) {
        return !user.getEmail().compare(email);
    };

    auto users = userHandler_.getUserDatabase();
    return *std::find_if(users.begin(), users.end(), byEmail);
}
