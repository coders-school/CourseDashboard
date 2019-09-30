#pragma once

#include "Lesson.hpp"
#include "User.hpp"
#include "Attendance.hpp"

#include <memory>
#include <unordered_map>

class AttendanceHandler
{
private:
  auto matchByEmail(const User& userProfile);

public:
  using AttendanceList = std::unordered_multimap<std::string, Attendance>;

  void reportAbsence(std::shared_ptr<const User> userProfile,
                     const Lesson& lesson, 
                     const std::string& comment);

  void reportMakeUp(std::shared_ptr<const User> userProfile,
                    const Lesson& lesson,
                    const Lesson& absenceLesson,
                    const std::string& comment);


  AttendanceList getReports(std::shared_ptr<const User> userProfile);

private:
  void report(std::shared_ptr<const User> userProfile,
              const Lesson& lesson,
              const std::string& absenceDate,
              const std::string& comment);

  AttendanceList attendanceList_;

};
