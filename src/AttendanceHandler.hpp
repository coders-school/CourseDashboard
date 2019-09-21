#pragma once

#include "Lesson.hpp"
#include "User.hpp"
#include "Attendance.hpp"

#include <unordered_map>

class AttendanceHandler
{
private:
  

  void report(const User& userProfile,
              const Lesson& Lesson,
              const std::string& absenceDate,
              const std::string& comment);

public:
  using AttendanceList = std::unordered_multimap<std::string, Attendance>;

  void reportAbsence(const User& userProfile,
                     const Lesson& Lesson, 
                     const std::string& comment);

  void reportMakeUp(const User& userProfile,
                    const Lesson& Lesson,
                    const std::string& absenceDate,
                    const std::string& comment);


  AttendanceList viewReports(const User * const userProfile);

private:
  AttendanceList attendanceList_;

};
