#include <gtest/gtest.h>
#include <Calender.hpp>
#include <algorithm>

struct CalendarTests : public ::testing::Test
{
    CalendarTests()
    {
        calender_.addLesson("Weekend", "2019-06-15", "16:30", "Environment configuration" );
        calender_.addLesson("Evening", "2019-07-06", "16:30", "Programming tools" );
        calender_.addLesson("Evening", "2019-07-07", "16:30", "Basics of C++" );
    }

    Calender calender_;
};

TEST_F(CalendarTests, can_add_and_view_Lesson)
{
    const auto& result = calender_.viewLesson("Evening", "2019-07-07", "16:30");
    EXPECT_EQ(result.getData(), "2019-07-07");
    EXPECT_EQ(result.getTime(),  "16:30");
    EXPECT_EQ(result.getSubject(), "Basics of C++");
}

TEST_F(CalendarTests, can_add_date_with_dot_slash_minus)
{
    calender_.addLesson("Weekend2", "2019/06/16", "16:30", "Environment configuration 2" );
    calender_.addLesson("Weekend3", "2019.06.17", "16:30", "Environment configuration 2" );

    const auto& result1 = calender_.viewLesson("Weekend2", "2019/06/16", "16:30");
    const auto& result2 = calender_.viewLesson("Weekend3", "2019.06.17", "16:30");

    ASSERT_EQ(result1.getData(), "2019/06/16");
    ASSERT_EQ(result2.getData(), "2019.06.17");
}

TEST_F(CalendarTests, can_add_date_In_revers_order)
{
    ASSERT_NO_THROW(calender_.addLesson("Weekend2", "16/06/2019", "16:30", "Environment configuration 2" ));
}

TEST_F(CalendarTests, throw_exception_if_date_or_time_is_in_the_incorrect_format)
{
    ASSERT_THROW(calender_.addLesson("Weekend2", "2019#06#16", "16:30", "Environment configuration 2" ), std::invalid_argument);
    ASSERT_THROW(calender_.addLesson("Weekend2", "2019.06.16", "16-30", "Environment configuration 2" ), std::invalid_argument);
}

TEST_F(CalendarTests, can_Not_Add_Two_Lessons_With_the_same_Group_Date_and_Time)
{
    ASSERT_THROW(calender_.addLesson("Weekend", "2019-06-15", "16:30", "Environment configuration" ), std::invalid_argument);
}

TEST_F(CalendarTests, can_Add_Two_Lessons_for_the_same_group_one_After_the_other)
{
    ASSERT_NO_THROW(calender_.addLesson("Weekend", "2019-06-16", "17:30", "Environment configuration" ));
}

TEST_F(CalendarTests, viewLesson_Throw_Exception_When_Group_Not_Found) {
    ASSERT_THROW(calender_.viewLesson("Evening3", "2019-07-06", "16:30");, std::invalid_argument);
}

TEST_F(CalendarTests, viewLesson_Throw_Exception_When_Data_Or_Time_Not_Found) {
    ASSERT_THROW(calender_.eraseLesson("Evening", "2019-07-10", "16:30"), std::invalid_argument);
    ASSERT_THROW(calender_.eraseLesson("Evening", "2019-07-06", "16:31"), std::invalid_argument);
}

TEST_F(CalendarTests, can_eraseLesson)
{
    calender_.eraseLesson("Evening", "2019-07-06", "16:30");
    ASSERT_THROW(calender_.viewLesson("Evening", "2019-07-06", "16:30"), std::invalid_argument);
}

TEST_F(CalendarTests, viewAllSchedules)
{
    auto result = calender_.viewSchedule("ALL");
    ASSERT_EQ(result.size(), 3);
}

TEST_F(CalendarTests, viewEveningSchedules)
{
    auto result = calender_.viewSchedule("Evening");
    ASSERT_EQ(result.size(), 2);
}
