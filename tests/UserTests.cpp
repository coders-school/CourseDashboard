#include <gtest/gtest.h>
#include "User.hpp"
#include "nlohmann/json.hpp"


struct UserTests : public ::testing::Test
{
    nlohmann::json jsonData = R"(
    {
        "name": "Ewa",
        "nick": "nick",
        "group": 1,
        "gitHub": "github",
        "firecod": "firecode"
    }
    )"_json;  // TODO: Change firecod, gitHub
    User ewa{jsonData};
    User adam{"Adam", "nick", User::Group::evening, "github", "firecode"};
};

TEST_F(UserTests, toJson)
{
    EXPECT_EQ(ewa.toJson(), jsonData);
}

TEST_F(UserTests, toString)
{
    auto expected = "1.Ewa|2.nick|3.evening|4.github|5.firecode|\n";
    auto stringData = ewa.toString();
    EXPECT_EQ(stringData, expected);
}