#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "User.hpp"

struct CourseDashboardTests : public ::testing::Test
{
    CourseDashboard CourseDashboard_;
    User testUser_;

    CourseDashboardTests()
    {
        CourseDashboard_.createUser(User("Stefan",
                                       "SBatory",
                                       "wieczorowa",
                                       "sbatory",
                                       "sbatory"));
        testUser_ = User("Jan",
                         "JanKowalski",
                         "weekendowa",
                         "jkowalski",
                         "jkowalski");
    }
};


TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}
