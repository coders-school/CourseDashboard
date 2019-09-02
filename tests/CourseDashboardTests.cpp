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
    auto result = CourseDashboard_.showAll();
    int recordsCount = std::count(result.begin(), result.end(), '\n');
    EXPECT_EQ(recordsCount, 2);
}

TEST_F(CourseDashboardTests, canDeleteUser)
{
    CourseDashboard_.deleteUserByNick("JanKowalski");
    auto result = CourseDashboard_.showAll();
    EXPECT_EQ(result, "");
}

