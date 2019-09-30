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

    return authenticationProvider(*user, email, password);
}

Calendar::Schedules CourseDashboard::viewSchedule(const std::string& email)
{
    if(!email.compare("")) {
        return calender_.getSchedule(User::Group::ALL);
    }

    auto user = findUserByEmail(email);
    return calender_.getSchedule(user->getGroup());
}

void CourseDashboard::reportAbsence(const std::string& email, 
                                    const std::string& date, 
                                    const std::string& time, 
                                    const std::string& comment)
{
    auto user = findUserByEmail(email);
    auto lesson = calender_.getLesson(user->getGroup(), date, time);

    attendanceHandler_.reportAbsence(user, lesson, comment);
}

void CourseDashboard::reportMakeUp(const std::string& email,
                                   const User::Group& group,
                                   const std::string& date, 
                                   const std::string& time,
                                   const std::string& absentDate,
                                   const std::string& absentTime,
                                   const std::string& comment)
{
    
    auto lesson = calender_.getLesson(group, date, time);

    auto user = findUserByEmail(email);
    auto absentLesson = calender_.getLesson(user->getGroup(), absentDate, absentTime);

    attendanceHandler_.reportMakeUp(user, lesson, absentLesson,  comment);
}

AttendanceHandler::AttendanceList CourseDashboard::viewAttendance(const std::string& email)
{
    if(!email.compare("")) {
        return attendanceHandler_.getReports(std::shared_ptr<const User>(nullptr));
    }

    auto user = findUserByEmail(email);
    return attendanceHandler_.getReports(user);
}


const std::shared_ptr<User> CourseDashboard::findUserByEmail(const std::string& email)
{
    auto byEmail = [&email](auto user) {
        return !user.getEmail().compare(email);
    };

    auto users = userHandler_.getUserDatabase();
    auto user = std::find_if(users.begin(), users.end(), byEmail);
    
    if(user == users.end()) {
        std::invalid_argument("User with email: " + email + "do not exist's");
    }

    return std::make_shared<User>(*user);
}
