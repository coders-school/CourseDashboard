
#include <gtest/gtest.h>

#include "CRUDControllerfixture.hpp"

TEST(CRUDControllerTests, canConstructCRUDController)
{
    CRUDControllerFx l_CRUDController;
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, canSearchUserByEmail)
{
    CRUDControllerFx l_CRUDController;
    std::string l_SearchResult;

    l_SearchResult = l_CRUDController.search("kamil.waszkiewicz.2@gmail.com");

    ASSERT_TRUE(l_SearchResult.find("kamil.waszkiewicz.2@gmail.com") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, NoAccountWithGivenEmail)
{
    CRUDControllerFx l_CRUDController;
    auto l_SearchResult = l_CRUDController.search("kamil.waszkiewicz.233@gmail.com");

    ASSERT_TRUE(!l_SearchResult.compare("CD001"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, canSearchUserByName)
{
    CRUDControllerFx l_CRUDController;
    auto l_SearchResult = l_CRUDController.search("Kamil");

    ASSERT_TRUE(l_SearchResult.find("Kamil") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, NoAccountWithGivenName)
{
    CRUDControllerFx l_CRUDController;
    auto l_SearchResult = l_CRUDController.search("Kamill");

    ASSERT_TRUE(!l_SearchResult.compare("CD001"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, canAddUser)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.add(
        "Joanna",
        "joanna@gmail.com",
        "jola",
        "https://github.com",
        "https://www.firecode.io",
        "Weekend");

    ASSERT_TRUE(!l_AddResult.compare("Successfully added user Joanna"));


    auto l_Result = l_CRUDController.search("joanna@gmail.com");

    ASSERT_TRUE(l_Result.find("jola") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, AddUserWithGroupThatDoNotExist)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.add(
        "Joanna",
        "joanna@gmail.com",
        "jola",
        "https://github.com",
        "https://www.firecode.io",
        "Weekend22");

    ASSERT_TRUE(!l_AddResult.compare("CD003"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, AddUserEmailIsInTheSystem)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.add(
        "Joanna",
        "0king.pp1115@chaonamdinh.com",
        "jola",
        "https://github.com",
        "https://www.firecode.io",
        "Weekend");

    ASSERT_TRUE(!l_AddResult.compare("CD004"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, canDeleteUser)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.remove("0king.pp1115@chaonamdinh.com");
    ASSERT_TRUE(!l_AddResult.compare("Successfully deleted User 0king.pp1115@chaonamdinh.com"));
    ASSERT_TRUE(!l_CRUDController.search("0king.pp1115@chaonamdinh.com").compare("CD001"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, DeleteUserIncorrectEmail)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.remove("0king.pp1115");
    ASSERT_TRUE(!l_AddResult.compare("CD005"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, DeleteEmailIsNotInTheSystem)
{
    CRUDControllerFx l_CRUDController;

    auto l_AddResult = l_CRUDController.remove("joanna@gmail.com");
    ASSERT_TRUE(!l_AddResult.compare("CD001"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, canUpdateUserData)
{
    CRUDControllerFx l_CRUDController;

    auto l_UpdateResult = l_CRUDController.update(
        "0king.pp1115@chaonamdinh.com", 
        "Joanna",
        "joanna@gmail.com",
        "jola",
        "https://github1.com",
        "https://www.firecode1.io",
        "Evening");

    ASSERT_TRUE(!l_UpdateResult.compare("Successfully Updated User data"));

    auto l_SearchResult = l_CRUDController.search("joanna@gmail.com");
    ASSERT_TRUE(l_SearchResult.find("joanna@gmail.com") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, UpdateFailTOFindOldEmail)
{
    CRUDControllerFx l_CRUDController;

    auto l_UpdateResult = l_CRUDController.update(
        "0king.pp",
        "Joanna",
        "joanna@gmail.com",
        "jola",
        "https://github1.com",
        "https://www.firecode1.io",
        "Evening22");

    ASSERT_TRUE(!l_UpdateResult.compare("CD005"));
}

//---------------------------------------------------------------------------------------

TEST(CRUDControllerTests, UpdateFailToAssignGroup)
{
    CRUDControllerFx l_CRUDController;

    auto l_UpdateResult = l_CRUDController.update(
        "0king.pp1115@chaonamdinh.com",
        "Joanna",
        "joanna@gmail.com",
        "jola",
        "https://github1.com",
        "https://www.firecode1.io",
        "Evening22");

    ASSERT_TRUE(!l_UpdateResult.compare("CD003"));
}