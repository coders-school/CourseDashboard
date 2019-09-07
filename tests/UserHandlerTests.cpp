#include <gtest/gtest.h>
#include "UserHandler.hpp"

TEST(UserHandlerTests, retriveUserFromEmptyDatabaseReturnsNullptr)
{
    UserHandler cut;
    ASSERT_EQ(cut.retriveUserByNick(""), nullptr);
}
