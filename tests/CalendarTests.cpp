#include <gtest/gtest.h>
#include <Calendar.hpp>
#include <algorithm>

struct CalendarTests : public ::testing::Test
{
    CalendarTests()
    {
        calender_.addLesson(User::Group::weekend, "2019-06-15", "10:00", "Environment configuration" );
        calender_.addLesson(User::Group::evening, "2019-06-15", "10:00", "Environment configuration" );
        calender_.addLesson(User::Group::weekend, "2019-07-06", "16:30", "Basics of C++" );
        calender_.addLesson(User::Group::evening, "2019-07-07", "16:30", "Basics of C++" );
    }

    Calendar calender_;
};

TEST_F(CalendarTests, can_add_and_view_Lesson)
{
    const auto& result = calender_.getLesson(User::Group::evening, "2019-07-07", "16:30");
    EXPECT_EQ(result.getDate(), "2019-07-07");
    EXPECT_EQ(result.getTime(),  "16:30");
    EXPECT_EQ(result.getSubject(), "Basics of C++");
}

TEST_F(CalendarTests, throw_invalid_argument_if_lesson_not_found)
{
    EXPECT_THROW(calender_.getLesson(User::Group::evening, "2019-07-09", "16:30"), std::invalid_argument);
    ASSERT_THROW(calender_.getLesson(User::Group::evening, "2019-07-07", "17:00"), std::invalid_argument);
}

TEST_F(CalendarTests, can_not_add_date_or_time_with_incorrect_Format)
{
    EXPECT_THROW(calender_.addLesson(User::Group::evening, "32/06/2019", "16:30", "sample_lesson" ), std::invalid_argument);
    ASSERT_THROW(calender_.addLesson(User::Group::evening, "31-13-2019", "16-30", "sample_lesson" ), std::invalid_argument);
}

TEST_F(CalendarTests, can_Not_Add_Two_Lessons_With_the_same_Group_Date_and_Time)
{
    ASSERT_THROW(calender_.addLesson(User::Group::weekend, "2019-06-15", "10:00", "Environment configuration" ), std::invalid_argument);
}

TEST_F(CalendarTests, can_Add_Two_Lessons_for_the_same_group_one_After_the_other)
{
    ASSERT_NO_THROW(calender_.addLesson(User::Group::weekend, "2019-07-06", "17:30", "Basics of C++ l2" ));
}

TEST_F(CalendarTests, get_All_Schedules)
{
    auto result = calender_.getSchedule(User::Group::ALL);
    ASSERT_EQ(result.size(), 4);
}

TEST_F(CalendarTests, get_Evening_Schedules)
{
    auto result = calender_.getSchedule(User::Group::evening);
    ASSERT_EQ(result.size(), 2);
}
