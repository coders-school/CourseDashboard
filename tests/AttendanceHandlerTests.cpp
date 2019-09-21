#include <gtest/gtest.h>

#include "Attendance.hpp"
#include "AttendanceHandler.hpp"
#include "Calender.hpp"

struct AttendanceHandlerTests : public ::testing::Test
{
    AttendanceHandler attendanceHandler_;
};

TEST_F(AttendanceHandlerTests, Can_Report_Absence_And_View_report)
{
    Lesson lesson("2019-07-06", "16:30", "temp Subject");
    User user("Kamil", "Kami", User::Group::evening, "Kami", "Kami", "k.w2@gmail.com", "xx");

    attendanceHandler_.reportAbsence(user, lesson, "I am have doctor appointment");
    ASSERT_EQ(attendanceHandler_.viewReports(&user).begin()->second.getEmail(), "k.w2@gmail.com");
}

TEST_F(AttendanceHandlerTests, Can_Report_Makeup_And_View_report)
{
    Lesson lesson("2019-07-07", "16:30", "temp Subject");
    User user("Kamil", "Kami", User::Group::evening, "Kami", "Kami", "k.w2@gmail.com", "xx");

    attendanceHandler_.reportMakeUp(user, lesson, "2019-07-06", "I am have doctor appointment");
    ASSERT_EQ(attendanceHandler_.viewReports(&user).begin()->second.getEmail(), "k.w2@gmail.com");
}

TEST_F(AttendanceHandlerTests, Can_Not_Report_The_same_issue_two_times)
{
    Lesson lesson("2019-07-07", "16:30", "temp Subject");
    User user("Kamil", "Kami", User::Group::evening, "Kami", "Kami", "k.w2@gmail.com", "xx");

    attendanceHandler_.reportMakeUp(user, lesson, "2019-07-06", "I am have doctor appointment");
    ASSERT_THROW(attendanceHandler_.reportMakeUp(user, lesson, "2019-07-06", "I am have doctor appointment"), std::invalid_argument);
}