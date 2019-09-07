#include <gtest/gtest.h>
#include "UserHandler.hpp"
#include "User.hpp"

TEST(UserHandlerTests, retriveUserFromEmptyDatabaseReturnsNullptr)
{
    UserHandler cut;
    ASSERT_EQ(cut.retriveUserByNick(""), nullptr);
}

TEST(UserHandlerTests, retriveUserFromDatabaseReturnsRequestedUser)
{
    UserHandler cut;
    std::string nick = "SzymonG";
    User szymon("Szymon", nick, User::Group::evening, "SzymonG", "SzymonG");
    cut.createUser(szymon);
    ASSERT_EQ(*cut.retriveUserByNick(nick), szymon);
}