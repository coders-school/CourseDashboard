#include <gtest/gtest.h>
#include <utility>

#include "models/AccountDAO.hpp"

TEST(AccountDAOTests, canConstructAccount)
{
    AccountDAO l_Account;
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canConstructAccountParametrized)
{

    AccountDAO l_Account("kamil.waszkiewicz.2@gmail.com", 199, 1);

    ASSERT_TRUE(l_Account.getID() == 1);
    ASSERT_TRUE(l_Account.getProfileID() == 199);
    ASSERT_TRUE(!l_Account.getEmail().compare("kamil.waszkiewicz.2@gmail.com"));


}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canConstructAccountByCopy)
{

    AccountDAO l_AccountToCopy("kamil.waszkiewicz.2@gmail.com", 199, 1);
    AccountDAO l_Account(l_AccountToCopy);

    ASSERT_TRUE(l_Account.getID() == 1);
    ASSERT_TRUE(l_Account.getProfileID() == 199);
    ASSERT_TRUE(!l_Account.getEmail().compare("kamil.waszkiewicz.2@gmail.com"));
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canAssignAccountByCopy)
{

    AccountDAO l_AccountToCopy("kamil.waszkiewicz.2@gmail.com", 199, 1);
    AccountDAO l_Account = l_AccountToCopy;

    ASSERT_TRUE(l_Account.getID() == 1);
    ASSERT_TRUE(l_Account.getProfileID() == 199);
    ASSERT_TRUE(!l_Account.getEmail().compare("kamil.waszkiewicz.2@gmail.com"));
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canConvertToString)
{

    AccountDAO l_Account("kamil.waszkiewicz.2@gmail.com", 199, 1);

    ASSERT_TRUE(l_Account.toString().find("kamil.waszkiewicz.2@gmail.com") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canGetSetID)
{
    AccountDAO l_Account;
    l_Account.setID(1);

    ASSERT_TRUE(l_Account.getID() == 1);
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canGetSetStudentID)
{
    AccountDAO l_Account;
    l_Account.setProfileID(199);

    ASSERT_TRUE(l_Account.getProfileID() == 199);
}

//---------------------------------------------------------------------------------------

TEST(AccountDAOTests, canGetSetEmail)
{
    AccountDAO l_Account;
    l_Account.setEmail("kamil.waszkiewicz.2@gmail.com");

    ASSERT_TRUE(!l_Account.getEmail().compare("kamil.waszkiewicz.2@gmail.com"));
}
