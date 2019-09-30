#include <gtest/gtest.h>
#include "UserHandler.hpp"
#include "User.hpp"

struct UserHandlerTests : public testing::Test
{
    UserHandler cut;
    std::string nick = "SzymonG";
    User szymon {"Szymon", nick, User::Group::evening, "SzymonG", "SzymonG"};
    User shrek {"Shrek", "shrek", User::Group::evening, "test1", "test2"};
};

TEST_F(UserHandlerTests, getAllUsersReturnsStringWithEachUserPerLine)
{
    EXPECT_EQ(cut.getAll(), "");

    cut.addUser(szymon);
    EXPECT_EQ(cut.getAll(), szymon.toString());

    cut.addUser(shrek);
    EXPECT_EQ(cut.getAll(), szymon.toString() + shrek.toString());
}

TEST_F(UserHandlerTests, retriveUserFromEmptyDatabaseReturnsNullptr)
{
    ASSERT_EQ(cut.retriveUserByNick(""), nullptr);
}

TEST_F(UserHandlerTests, retriveUserFromDatabaseReturnsRequestedUser)
{
    cut.addUser(szymon);
    ASSERT_EQ(*cut.retriveUserByNick(nick), szymon);
}

TEST_F(UserHandlerTests, retriveNotExistingUserReturnsNullptr)
{
    cut.addUser(szymon);
    ASSERT_EQ(cut.retriveUserByNick("nonExisting"), nullptr);
}

TEST_F(UserHandlerTests, deleteNotExistingUserDoesNothing)
{
    cut.addUser(szymon);
    auto beforeDelete = cut.getUserDatabase();
    cut.deleteUserByNick("nonExisting");
    ASSERT_EQ(beforeDelete, cut.getUserDatabase());
}

TEST_F(UserHandlerTests, deleteUserDeletesRequestedUser)
{
    cut.addUser(szymon);
    auto beforeDelete = cut.getUserDatabase();
    cut.deleteUserByNick(nick);
    ASSERT_NE(beforeDelete, cut.getUserDatabase());
}

TEST_F(UserHandlerTests, updateUserAffectsRequestedUser)
{
    cut.addUser(szymon);
    auto szymonBeforeChange = cut.retriveUserByNick(nick);
    cut.updateUser(szymonBeforeChange, User::Group::weekend, "NotSzymon","NotSzymonG", "NotSzymonG","NotSzymonG");
    auto szymonAfterChange = cut.retriveUserByNick(nick);
    ASSERT_NE(szymonBeforeChange, szymonAfterChange);
}

TEST_F(UserHandlerTests, updateUserDoesntAffectOtherUsers)
{
    cut.addUser(szymon);
    auto szymonBeforeChange = cut.retriveUserByNick(nick);
    cut.updateUser(&shrek, User::Group::weekend, "NotSzymon","NotSzymonG", "NotSzymonG","NotSzymonG");
    auto szymonAfterChange = cut.retriveUserByNick(nick);
    ASSERT_EQ(szymonBeforeChange, szymonAfterChange);
}

TEST_F(UserHandlerTests, clearUserDatabaseErasesWholeDb)
{
    cut.addUser(szymon);
    cut.addUser(shrek);
    auto beforeClear = cut.getUserDatabase();
    cut.clearUserDatabase();
    auto afterClear = cut.getUserDatabase();
    ASSERT_NE(beforeClear, afterClear);
    ASSERT_TRUE(afterClear.empty());
}
