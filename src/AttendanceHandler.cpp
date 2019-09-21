
#include <algorithm>
#include "AttendanceHandler.hpp"

void AttendanceHandler::report(const User& userProfile,
                               const Lesson& Lesson,
                               const std::string& action,
                               const std::string& comment)
{
    std::string key = Lesson.getDate() + "T" + Lesson.getTime();
    auto reportList = attendanceList_.equal_range(key);
    
    auto prediction = [&userProfile](const auto& report)
    {
        if(report.second.getEmail() == userProfile.getEmail()) {
            return true;
        }
        return false;
    };
    
    if(reportList.first == attendanceList_.end() or 
       std::find_if(reportList.first, reportList.second, prediction) == attendanceList_.end())
    {
        attendanceList_.emplace(key, Attendance(userProfile.getEmail(), userProfile.getName(), action, comment));
        return;
    }

    throw std::invalid_argument("You report have been recived");
}


void AttendanceHandler::reportAbsence(const User& userProfile,
                                      const Lesson& Lesson,
                                      const std::string& comment)
{
    report(userProfile, Lesson, "Absence", comment);
}

void AttendanceHandler::reportMakeUp(const User& userProfile,
                                     const Lesson& Lesson,
                                     const std::string& absenceDate,
                                     const std::string& comment)
{
    report(userProfile, Lesson, "MakeUp for: " + absenceDate, comment);
}

AttendanceHandler::AttendanceList AttendanceHandler::viewReports(const User * const userProfile = nullptr)
{
    if(userProfile == nullptr) {
        return attendanceList_;
    }

    AttendanceHandler::AttendanceList allUserReports;

    auto matchByEmail = [&userProfile](const auto& r) {
        return !r.second.getEmail().compare(userProfile->getEmail());
    };

    std::copy_if(attendanceList_.begin(), attendanceList_.end(), std::inserter(allUserReports, allUserReports.begin()), matchByEmail);
    return allUserReports;
}