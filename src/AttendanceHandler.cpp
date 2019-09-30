
#include <algorithm>
#include "AttendanceHandler.hpp"

auto AttendanceHandler::matchByEmail(const User& userProfile)
{
    return [&userProfile](const auto& report)
    {
        return !report.second.getEmail().compare(userProfile.getEmail());
    };
}

void AttendanceHandler::reportAbsence(std::shared_ptr<const User> userProfile,
                                      const Lesson& lesson,
                                      const std::string& comment)
{
    report(userProfile, lesson, "Absence", comment);
}

void AttendanceHandler::reportMakeUp(std::shared_ptr<const User> userProfile,
                                     const Lesson& lesson,
                                     const Lesson& absenceLesson,
                                     const std::string& comment)
{
    report(userProfile, lesson, "MakeUp for: " + absenceLesson.getDate() + " " + absenceLesson.getTime(), comment);
}

void AttendanceHandler::report(std::shared_ptr<const User> userProfile,
                               const Lesson& lesson,
                               const std::string& action,
                               const std::string& comment)
{
    std::string key = lesson.getDate() + " " + lesson.getTime();
    auto reportList = attendanceList_.equal_range(key);
    
    auto user = std::find_if(reportList.first, 
                             reportList.second, 
                             matchByEmail(*userProfile));


    if(reportList.first == attendanceList_.end() or 
       user == attendanceList_.end())
    {
        attendanceList_.emplace(key, Attendance(userProfile->getEmail(), 
                                                userProfile->getName(), 
                                                action, 
                                                comment));
        return;
    }

    throw std::invalid_argument("You report have been recived");
}

AttendanceHandler::AttendanceList AttendanceHandler::getReports(std::shared_ptr<const User> userProfile)
{
    if(not userProfile) {
        return attendanceList_;
    }

    AttendanceHandler::AttendanceList userReports;

    std::copy_if(attendanceList_.begin(), 
                 attendanceList_.end(), 
                 std::inserter(userReports, userReports.begin()), 
                 matchByEmail(*userProfile));

    return userReports;
}
