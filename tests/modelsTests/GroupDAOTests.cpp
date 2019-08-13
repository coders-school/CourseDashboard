#include <gtest/gtest.h>
#include <utility>

#include "models/GroupDAO.hpp"

TEST(GroupDAOTests, canConstructGroup)
{
    GroupDAO l_Group;
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canConstructGroupParametrized)
{
    GroupDAO l_Group("Weekend", 1);
    
    ASSERT_TRUE(l_Group.getID() == 1);
    ASSERT_TRUE(!l_Group.getGroupName().compare("Weekend"));
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canConstructGroupByCopy)
{
    GroupDAO l_GroupToCopy("Weekend", 1);
    GroupDAO l_Group(l_GroupToCopy);

    ASSERT_TRUE(l_Group.getID() == 1);
    ASSERT_TRUE(!l_Group.getGroupName().compare("Weekend"));
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canAssignGroupByCopy)
{
    GroupDAO l_GroupToCopy("Weekend", 1);
    GroupDAO l_Group = l_GroupToCopy;

    ASSERT_TRUE(l_Group.getID() == 1);
    ASSERT_TRUE(!l_Group.getGroupName().compare("Weekend"));
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canConvertToString)
{
    GroupDAO l_Group("Weekend", 1);

    ASSERT_TRUE(l_Group.toString().find("Weekend") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canGetSetStudentID)
{
    GroupDAO l_Group;
    l_Group.setID(1);

    ASSERT_TRUE(l_Group.getID() == 1);
}

//---------------------------------------------------------------------------------------

TEST(GroupDAOTests, canGetSetGroupName)
{
    GroupDAO l_Group;
    l_Group.setGroupName("this is time group name");

    ASSERT_TRUE(!l_Group.getGroupName().compare("this is time group name"));
}
