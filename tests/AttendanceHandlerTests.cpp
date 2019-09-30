#include <gtest/gtest.h>

#include "Attendance.hpp"
#include "AttendanceHandler.hpp"
#include "Calendar.hpp"

struct AttendanceHandlerTests : public ::testing::Test
{
    AttendanceHandlerTests() :
    lesson("2019-07-06", "16:30", "temp Subject"),
    absentLesson("2019-07-05", "16:30", "lesson 2"),
    user(std::make_shared<User>("Kamil", 
                                "Kami", 
                                User::Group::evening, 
                                "Kami", 
                                "Kami", 
                                "k.w2@gmail.com", 
                                "xx"))
    {
        
    }
    
    AttendanceHandler attendanceHandler_;

    Lesson lesson;
    Lesson absentLesson;
    std::shared_ptr<User> user;
};


TEST_F(AttendanceHandlerTests, Can_Report_Absence_And_View_report)
{
    attendanceHandler_.reportAbsence(user, lesson, "I am have doctor appointment");
    ASSERT_EQ(attendanceHandler_.getReports(user).begin()->second.getEmail(), "k.w2@gmail.com");
}

TEST_F(AttendanceHandlerTests, Can_Report_Makeup_And_View_report)
{
    attendanceHandler_.reportMakeUp(user, lesson, absentLesson, "I am have doctor appointment");
    ASSERT_EQ(attendanceHandler_.getReports(user).begin()->second.getEmail(), "k.w2@gmail.com");
}

TEST_F(AttendanceHandlerTests, Can_Not_Report_The_same_issue_two_times)
{

    attendanceHandler_.reportMakeUp(user, lesson, absentLesson, "I am have doctor appointment");
    ASSERT_THROW(attendanceHandler_.reportMakeUp(user, lesson, absentLesson, "I am have doctor appointment"), std::invalid_argument);
}

TEST_F(AttendanceHandlerTests, Can_get_all_reports)
{
    attendanceHandler_.reportAbsence(user, absentLesson, "I am have doctor appointment");
    attendanceHandler_.reportMakeUp(user, lesson, absentLesson, "I am have doctor appointment");
    ASSERT_EQ(attendanceHandler_.getReports(nullptr).size(), 2); 
}