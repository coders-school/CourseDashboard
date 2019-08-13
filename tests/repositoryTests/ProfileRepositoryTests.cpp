#include <gtest/gtest.h>

#include "repository/ProfileRepositoryImpl.hpp"
#include "models/ProfileDAO.hpp"

class ProfileFixture 
{
public:
    ProfileFixture ()
    {
        std::vector<ProfileDAO> m_Context = {
            ProfileDAO("Kamil",     "kamil.waszkiewicz",    "https://github.com",   "https://www.firecode.io",   1,  1),
            ProfileDAO("Tester1",   "0king.pp1115",         "https://github.com",   "https://www.firecode.io",   1,  2),
            ProfileDAO("Kamil",    "fanjel",               "https://github.com",   "https://www.firecode.io",   2,  3),
            ProfileDAO("Tester3",   "9ayoub",               "https://github.com",   "https://www.firecode.io",   2,  4),
        };

        ProfileRepositoryImpl l_Repository(m_Context);
        m_Repository = l_Repository;
    };

//---------------------------------------------------------------------------------------

    ProfileRepositoryImpl& getRepository() {
        return m_Repository;
    }

private:

    ProfileRepositoryImpl m_Repository;
};

TEST(ProfileRepositoryTests, canConstructProfileRepository)
{
    std::vector<ProfileDAO> m_Context;
    ProfileRepositoryImpl l_Repository(m_Context);
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canGetProfileByName)
{
 
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByName("Tester1");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().empty());
    ASSERT_TRUE(!l_Result.value()[0].getName().compare("Tester1"));
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, userWithGivenNameDoNotExists)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByName("Tester1123");

    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canGetProfileByNick)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByNick("0king.pp1115");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().empty());
    ASSERT_TRUE(!l_Result.value()[0].getDiscordNick().compare("0king.pp1115"));
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, userWithGivenNickDoNotExists)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByNick("Tester1123");

    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canGetProfilesByGroup)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroup(2);

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().empty());
    ASSERT_TRUE(l_Result.value()[0].getGroupID() == 2);
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, usersAreNotAssignedTogivenGroup)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroup(3);

    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canGetProfileByID)
{
    ProfileFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByID(2);

    ASSERT_TRUE(l_Result.getID() == 2);
    ASSERT_TRUE(!l_Result.getName().compare("Tester1"));
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canRemoveProfile)
{
    ProfileFixture  l_Fx;
    auto l_Profile = l_Fx.getRepository().getByName("Tester1");

    ASSERT_TRUE(l_Profile.has_value());


    l_Fx.getRepository().remove(l_Profile.value()[0]);
    auto l_Result = l_Fx.getRepository().getByName("Tester1");

    ASSERT_FALSE(l_Result.has_value());
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canRemoveProfileByID)
{
    ProfileFixture  l_Fx;

    auto l_Profile = l_Fx.getRepository().getByName("Tester1");

    ASSERT_TRUE(l_Profile.has_value());


    l_Fx.getRepository().remove(l_Profile.value()[0].getID());
    auto l_resultr = l_Fx.getRepository().getByName("0king.pp1115@chaonamdinh.com");

    ASSERT_FALSE(l_resultr.has_value());
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, canUpdateProfile)
{
    ProfileFixture  l_Fx;
    auto l_ProfileArray= l_Fx.getRepository().getByName("Tester1");

    ASSERT_TRUE(l_ProfileArray.has_value());

    auto l_profile = l_ProfileArray.value()[0];

    l_profile.setName("Olga");
    l_profile.setGroupID(2);


    l_Fx.getRepository().update(l_profile);
    auto l_Result = l_Fx.getRepository().getByName("Olga");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value()[0].getName().compare("Olga"));
}

//---------------------------------------------------------------------------------------

TEST(ProfileRepositoryTests, Insertprofile)
{
    ProfileDAO l_Profile("Marcin", "MM", "www.google.pl", "www.google.pl", 1, 5);
    ProfileFixture  l_Fx;

    l_Fx.getRepository().insert(l_Profile);
    auto l_Result = l_Fx.getRepository().getByName("Marcin");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value()[0].getName().compare("Marcin"));
}
