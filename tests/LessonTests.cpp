#include <gtest/gtest.h>
#include "Lesson.hpp"

TEST(LessonTests, can_Initialize_class_Lesson_and_get_Data)
{
    Lesson lesson("10.02.2019", "16:30", "Tests of C++");
    ASSERT_EQ(lesson.getData(), "10.02.2019");
    ASSERT_EQ(lesson.getTime(), "16:30");
    ASSERT_EQ(lesson.getSubject(), "Tests of C++");
}
