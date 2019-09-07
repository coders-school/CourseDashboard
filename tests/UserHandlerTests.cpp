#include <gtest/gtest.h>
#include "UserHandler.hpp"
#include "User.hpp"

struct UserHandlerTests : public testing::Test
{
    UserHandler cut;
    std::string nick = "SzymonG";
    User szymon {"Szymon", nick, User::Group::evening, "SzymonG", "SzymonG"};
};

TEST_F(UserHandlerTests, retriveUserFromEmptyDatabaseReturnsNullptr)
{
    ASSERT_EQ(cut.retriveUserByNick(""), nullptr);
}

TEST_F(UserHandlerTests, retriveUserFromDatabaseReturnsRequestedUser)
{
    cut.createUser(szymon);
    ASSERT_EQ(*cut.retriveUserByNick(nick), szymon);
}

TEST_F(UserHandlerTests, retriveNotExistingUserReturnsNullptr)
{
    cut.createUser(szymon);
    ASSERT_EQ(cut.retriveUserByNick("nonExisting"), nullptr);
}