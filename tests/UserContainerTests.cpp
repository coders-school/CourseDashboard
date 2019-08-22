#include <gtest/gtest.h>

#include "UserContainer.hpp"
#include "User.hpp"

struct UserContainerTests : public ::testing::Test
{
    UserContainerTests()
    {
        userContainer_.createUser(User("Kamil", 
                                       "Kamil.Waszkiewicz", 
                                       "wieczorowa", 
                                       "Kamil.Waszkiewicz.gitHub", 
                                       "Kamil.Waszkiewicz.Firecode", 
                                       "Kamil.Waszkiewicz.Email", 
                                       "Kamil.Waszkiewicz.Password"));
        testUser_ = User("Szymon", 
                         "SzymonGajewski", 
                         "wieczorowa", 
                         "SzymonGajewski", 
                         "SzymonGajewski", 
                         "SzymonGajewski", 
                         "SzymonGajewski");
    }

    UserContainer userContainer_;
    User testUser_;
};

TEST_F(UserContainerTests, canConstructUserContainer)
{
    UserContainer uc;
}

TEST_F(UserContainerTests, canAddUserToUserContainer)
{
    userContainer_.createUser(testUser_);
    
    auto result = userContainer_.retriveUserByNick("SzymonGajewski");
    ASSERT_TRUE(result.has_value());
    
    ASSERT_TRUE(!result.value().getNick().compare("SzymonGajewski"));
}

TEST_F(UserContainerTests, canViewAllUsers)
{    
    auto result = userContainer_.showAll();
    ASSERT_TRUE(result.str().find("Kamil.Waszkiewicz") != std::string::npos);
}

TEST_F(UserContainerTests, canDeleteAUserInDatabase)
{    
    userContainer_.createUser(testUser_);

    auto result = userContainer_.retriveUserByNick("SzymonGajewski");
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(!result.value().getNick().compare("SzymonGajewski"));

    userContainer_.deleteUserByNick("SzymonGajewski");
    result = userContainer_.retriveUserByNick("SzymonGajewski");
    ASSERT_FALSE(result.has_value());
}

TEST_F(UserContainerTests, cantDeleteAUserNotInDatabase)
{    
    auto result = userContainer_.retriveUserByNick("SzymonGajewski");
    ASSERT_FALSE(result.has_value());
}

TEST_F(UserContainerTests, canUpdateUser)
{    
    auto result = userContainer_.retriveUserByNick("Kamil.Waszkiewicz");
    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(!result.value().getNick().compare("Kamil.Waszkiewicz"));

    result.value().setName("Szymon");
    result.value().setNick("Kamil.Waszkiewicz");
    result.value().setGroup("weekendowa");
    result.value().setGitHub("Kamil.Waszkiewicz");
    result.value().setFirecode("SzymonGajewski");

    userContainer_.updateUser(result.value());
    result = userContainer_.retriveUserByNick("Kamil.Waszkiewicz");

    ASSERT_TRUE(result.has_value());
    ASSERT_TRUE(!result.value().getName().compare("Szymon"));
}