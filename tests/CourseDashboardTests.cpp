#include <gtest/gtest.h>
#include "CourseDashboard.hpp"
#include "User.hpp"

class CourseDashboardTests : public ::testing::Test
{
public:
    CourseDashboard CourseDashboard_;

    User testUser1{"Jan",
                  "JanKowalski",
                  "weekendowa",
                  "jkowalski",
                  "jkowalski"};

    User testUser2{"Stefan",
                  "StefanNowak",
                  "weekendowa",
                  "snowak",
                  "snowak"};

    CourseDashboardTests() = default;

    void SetUp( ) override {
        CourseDashboard_.createUser(testUser1);
    }

    void TearDown() override {

    }
};


TEST_F(CourseDashboardTests, canConstructCourseDashboard)
{
    CourseDashboard cd;
}

TEST_F(CourseDashboardTests, canAddAnotherUser)
{
    CourseDashboard_.createUser(testUser2);
}

