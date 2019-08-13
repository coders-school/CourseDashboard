#include <gtest/gtest.h>

#include "models/AccountDAO.hpp"
#include "repository/AccountRepositoryImpl.hpp"
#include "CDExceptions.hpp"


class AccountFixture 
{
public:
    AccountFixture ()
    {
        std::vector<AccountDAO> m_Context = {
            AccountDAO("kamil.waszkiewicz.2@gmail.com", 1,  1),
            AccountDAO("0king.pp1115@chaonamdinh.com",  2,  2),
            AccountDAO("fanjel.a@surat.ddnsfree.com",   3,  3),
            AccountDAO("9ayoub.geoc@design-42.ru",      4,  4),
        };

        AccountRepositoryImpl l_Repository(m_Context);
        m_Repository = l_Repository;
    };

//---------------------------------------------------------------------------------------

    AccountRepositoryImpl& getRepository() {
        return m_Repository;
    }

private:

    AccountRepositoryImpl m_Repository;
};

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canConstructAccountRepository)
{
    std::vector<AccountDAO> l_Context;
    AccountRepositoryImpl l_Repository(l_Context);
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canGetAccountByEmail)
{
    AccountFixture  l_Fx;

    auto l_Result = l_Fx.getRepository().getByEmail("kamil.waszkiewicz.2@gmail.com");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().getEmail().compare("kamil.waszkiewicz.2@gmail.com"));
    ASSERT_TRUE(l_Result.value().getID() == 1);

}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, noEmailInDatabase)
{
    AccountFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByEmail("kamil.waszkiewicz.22@gmail.com");
    
    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canGetAccountByStudentID)
{
    AccountFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByStudentID(2);
    
    ASSERT_TRUE(!l_Result.getEmail().compare("0king.pp1115@chaonamdinh.com"));
    ASSERT_TRUE(l_Result.getProfileID() == 2);
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canGetAll)
{
    AccountFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getAll();
    
    ASSERT_TRUE(l_Result.size() != 0);
    ASSERT_TRUE(!l_Result[0].getEmail().compare("kamil.waszkiewicz.2@gmail.com"));
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canGetAccountByID)
{
    AccountFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByID(2);

    ASSERT_TRUE(l_Result.getID() == 2);
    ASSERT_TRUE(!l_Result.getEmail().compare("0king.pp1115@chaonamdinh.com"));
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canRemoveAccount)
{
    AccountFixture  l_Fx;
    auto l_Account = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");
    
    ASSERT_TRUE(l_Account.has_value());
    
    l_Fx.getRepository().remove(l_Account.value());

    auto l_Result = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");
    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canRemoveAccountByID)
{
    AccountFixture  l_Fx;
    auto l_Account = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");

    ASSERT_TRUE(l_Account.has_value());


    l_Fx.getRepository().remove(l_Account.value().getID());
    auto l_resultr = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");
    
    ASSERT_FALSE(l_resultr.has_value());
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canNotRemoveAccountTwoTimes)
{
    AccountFixture  l_Fx;
    auto l_Account = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");

    ASSERT_TRUE(l_Account.has_value());


    l_Fx.getRepository().remove(l_Account.value().getID());
    ASSERT_THROW(l_Fx.getRepository().remove(l_Account.value().getID()), NoSuchUserException);
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canUpdateAccount)
{
    AccountFixture  l_Fx;
    auto l_Account = l_Fx.getRepository().getByEmail("0king.pp1115@chaonamdinh.com");
    
    ASSERT_TRUE(l_Account.has_value());

    l_Account.value().setEmail("ammar@cathead.ru");

    l_Fx.getRepository().update(l_Account.value());
    auto l_Result = l_Fx.getRepository().getByEmail("ammar@cathead.ru");
    
    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().getEmail().compare("ammar@cathead.ru"));
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canInsertAccount)
{
    AccountDAO l_Account("ammar@cathead.ru", true);
    AccountFixture  l_Fx;

    ASSERT_NO_THROW(l_Fx.getRepository().insert(l_Account));
    auto l_Result = l_Fx.getRepository().getByEmail("ammar@cathead.ru");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().getEmail().compare("ammar@cathead.ru"));
}

//---------------------------------------------------------------------------------------

TEST(AccountRepositoryTests, canNotInsertAccountTwoTimes)
{
    AccountDAO l_Account("ammar@cathead.ru", true);
    AccountFixture  l_Fx;

    ASSERT_NO_THROW(l_Fx.getRepository().insert(l_Account));
    auto l_Result = l_Fx.getRepository().getByEmail("ammar@cathead.ru");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().getEmail().compare("ammar@cathead.ru"));
    ASSERT_THROW(l_Fx.getRepository().insert(l_Account), UniqueEntryException);
}