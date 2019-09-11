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

TEST_F(UserHandlerTests, deleteNotExistingUserDoesNothing)
{
    cut.createUser(szymon);
    auto beforeDelete = cut.getUserDatabase();
    cut.deleteUserByNick("nonExisting");
    ASSERT_EQ(beforeDelete, cut.getUserDatabase());
}

TEST_F(UserHandlerTests, deleteUserDoesDeleteRequestedUser)
{
    cut.createUser(szymon);
    auto beforeDelete = cut.getUserDatabase();
    cut.deleteUserByNick(nick);
    ASSERT_NE(beforeDelete, cut.getUserDatabase());
}

TEST_F(UserHandlerTests, updateUserAffectRequestedUser)
{
    cut.createUser(szymon);
    auto szymonBeforeChange = cut.retriveUserByNick(nick);
    cut.updateUser(szymonBeforeChange, User::Group::weekend, "NotSzymon","NotSzymonG", "NotSzymonG","NotSzymonG");
    auto szymonAfterChange = cut.retriveUserByNick(nick);
    ASSERT_NE(szymonBeforeChange, szymonAfterChange);
}

TEST_F(UserHandlerTests, updateUserDoesntAffectOtherUsers)
{
    cut.createUser(szymon);
    auto szymonBeforeChange = cut.retriveUserByNick(nick);
    cut.updateUser(&szymon, User::Group::weekend, "NotSzymon","NotSzymonG", "NotSzymonG","NotSzymonG");
    auto szymonAfterChange = cut.retriveUserByNick(nick);
    ASSERT_EQ(szymonBeforeChange, szymonAfterChange);
}