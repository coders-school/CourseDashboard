#include <gtest/gtest.h>

#include "Attendance.hpp"

TEST(AttendanceTests, userCanReporthAbsence)
{
    Attendance attendance("k.w2@gmail.com", "Kamil", "Absence", "I am have doctor appointment");

    ASSERT_EQ(attendance.getAction(), "Absence");
    ASSERT_EQ(attendance.getEmail(), "k.w2@gmail.com");
    ASSERT_EQ(attendance.getComment(), "I am have doctor appointment");
    ASSERT_EQ(attendance.getName(), "Kamil");
}