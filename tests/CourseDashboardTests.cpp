#include <gtest/gtest.h>
#include "CourseDashboard.hpp"


struct CourseDashboardTests : testing::Test
{
    CourseDashboard cd;
};

TEST_F(CourseDashboardTests, cantLogInWhenProvidedEmailIsNotInDb)
{
    EXPECT_FALSE(cd.login("email", "password"));
}

TEST_F(CourseDashboardTests, cantLogInWhenProvidedPasswordIsWrong)
{
    cd.loadFromJson("test_data.txt");
    EXPECT_FALSE(cd.login("papa@smerf.com", "klakier"));
}

TEST_F(CourseDashboardTests, canLogInWhenProvidedPasswordIsCorrect)
{
    cd.loadFromJson("test_data.txt");
    EXPECT_TRUE(cd.login("papa@smerf.com", "smerfetka"));
}

TEST_F(CourseDashboardTests, savingAndLoadingFromJson)
{
    EXPECT_TRUE(cd.userHandler_.getUserDatabase().empty());
    cd.loadFromJson("test_data.txt");
    EXPECT_FALSE(cd.userHandler_.getUserDatabase().empty());

    cd.saveToJson("test.json");
    auto beforeLoad = cd.userHandler_.getUserDatabase();
    cd.loadFromJson("test.json");
    auto afterLoad = cd.userHandler_.getUserDatabase();
    EXPECT_EQ(beforeLoad, afterLoad);
}
