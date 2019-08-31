#include <gtest/gtest.h>

#include "UserContainer.hpp"
#include "User.hpp"

struct UserContainerTests : public ::testing::Test
{
    UserContainerTests()
    {
        userContainer_.add(User("Kamil", "Kamil.Waszkiewicz", "wieczorowa", "Kamil.Waszkiewicz", "Kamil.Waszkiewicz"));
    }

    UserContainer userContainer_;
};

TEST_F(UserContainerTests, canConstructUserContainer)
{
    UserContainer uc;
}

TEST_F(UserContainerTests, canAddUserToUserContainer)
{
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    userContainer_.add(std::move(u1));
    
    const User& user = userContainer_.getUserByNick("SzymonGajewski");

    User expectedUser("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    ASSERT_TRUE(user == expectedUser);
}

TEST_F(UserContainerTests, canNotAddEmptyUserObjectToUserContainer)
{
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    userContainer_.add(std::move(u1));
    
    ASSERT_THROW(userContainer_.add(std::move(u1)), std::invalid_argument);
}

TEST_F(UserContainerTests, canNotAddUsersHavingTheSameData)
{
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    User u2("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    userContainer_.add(std::move(u1));
    
    ASSERT_THROW(userContainer_.add(std::move(u2)), std::invalid_argument);
}

TEST_F(UserContainerTests, canViewAllUsers)
{    
    auto result = userContainer_.showAll();
    ASSERT_TRUE(result.str().find("Kamil.Waszkiewicz") != std::string::npos);
}

TEST_F(UserContainerTests, canDeleteAUser)
{    
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    userContainer_.add(std::move(u1));

    userContainer_.deleteUserByNick("SzymonGajewski");
    ASSERT_THROW(userContainer_.getUserByNick("SzymonGajewski"), std::invalid_argument);
}

TEST_F(UserContainerTests, canNotDeleteUserNotInDatabase)
{    
    ASSERT_THROW(userContainer_.deleteUserByNick("SzymonGajewski"), std::invalid_argument);
}

TEST_F(UserContainerTests, canUpdateUser)
{    
    User& result = userContainer_.retriveUser(userContainer_.getUserByNick("Kamil.Waszkiewicz"));
    result.setNick("New.Kamil.Waszkiewicz");

    ASSERT_NO_THROW(userContainer_.getUserByNick("New.Kamil.Waszkiewicz").getNick());
}