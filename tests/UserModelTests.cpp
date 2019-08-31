#include <gtest/gtest.h>

#include "User.hpp"
#include "UserContainer.hpp"

struct Data
{
    const std::string name = "Kamil";
    const std::string nick = "Kamil.Waszkiewicz";
    const std::string group = "weekend";
    const std::string github = "Github";
    const std::string firecode = "Firecode";
} data;


TEST(UserModelTests, canConstructUserAndRetriveUsingGetAllInfo)
{
    User user(data.name, data.nick, data.group, data.github, data.firecode);
    
    auto text = user.getAllInfo();
    EXPECT_TRUE(text.find(data.name) != std::string::npos);
    EXPECT_TRUE(text.find(data.nick) != std::string::npos);
    EXPECT_TRUE(text.find(data.group) != std::string::npos);
    EXPECT_TRUE(text.find(data.github) != std::string::npos);
    EXPECT_TRUE(text.find(data.firecode) != std::string::npos);
}

TEST(UserModelTests, canSetUserData)
{
    User user(data.name, data.nick, data.group, data.github, data.firecode);
    user.setName("Tomek");
    user.setNick("Tomo");
    user.setGroup("noGroup");
    user.setGitHub("GG");
    user.setFirecode("FC");

    auto result = user.getAllInfo();

    EXPECT_TRUE(!user.getName().compare("Tomek"));
    EXPECT_TRUE(!user.getNick().compare("Tomo"));
    EXPECT_TRUE(result.find("noGroup") != std::string::npos);
    EXPECT_TRUE(result.find("GG") != std::string::npos);
    EXPECT_TRUE(result.find("FC") != std::string::npos);
}


TEST(UserModelTests, canCompareUserDataTheSameUsers)
{
    User user(data.name, data.nick, data.group, data.github, data.firecode);
    User user2(data.name, data.nick, data.group, data.github, data.firecode);

    ASSERT_TRUE(user == user2);
}