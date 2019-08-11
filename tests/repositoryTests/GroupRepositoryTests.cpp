#include <gtest/gtest.h>

#include "repository/GroupRepositoryImpl.hpp"
#include "models/GroupDAO.hpp"

class GroupFixture 
{
public:
    GroupFixture ()
    {
        std::vector<GroupDAO> m_Context = {
            GroupDAO("Weekend", 1),
            GroupDAO("Evening", 2)
        };

        GroupRepositoryImpl l_Repository(m_Context);
        m_Repository = l_Repository;
    };

//---------------------------------------------------------------------------------------

    GroupRepositoryImpl& getRepository() {
        return m_Repository;
    }

private:
    GroupRepositoryImpl m_Repository;
};

//---------------------------------------------------------------------------------------

TEST(GroupRepositoryTests, canConstructGroupRepository)
{
    std::vector<GroupDAO> l_Context;
    GroupRepositoryImpl l_Repository(l_Context);
}

TEST(GroupRepositoryTests, canGetGroupByID)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByID(1);

    ASSERT_TRUE(l_Result.getID() == 1);
    ASSERT_FALSE(!l_Result.getGroupName().compare(""));

}

TEST(GroupRepositoryTests, canGetGroupByName)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroupName("Evening");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(l_Result.value().getID() == 2);
}

TEST(GroupRepositoryTests, canGetAllGroups)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getAll();

    ASSERT_TRUE(l_Result.size() > 1);
    ASSERT_TRUE(l_Result[0].getID() == 1);
}

TEST(GroupRepositoryTests, canRemoveGroupByObject)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroupName("Evening");
    
    ASSERT_TRUE(l_Result.has_value());
    l_Fx.getRepository().remove(l_Result.value());

    l_Result = l_Fx.getRepository().getByGroupName("Evening");

    ASSERT_FALSE(l_Result.has_value());
}

TEST(GroupRepositoryTests, canRemoveGroupByID)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroupName("Evening");

    ASSERT_TRUE(l_Result.has_value());
    l_Fx.getRepository().remove(l_Result.value().getID());

    l_Result = l_Fx.getRepository().getByGroupName("Evening");

    ASSERT_FALSE(l_Result.has_value());
}

TEST(GroupRepositoryTests, canUpdateGroup)
{
    GroupFixture  l_Fx;
    auto l_Result = l_Fx.getRepository().getByGroupName("Evening");


    ASSERT_TRUE(l_Result.has_value());

    l_Result.value().setGroupName("Evening 1");
    l_Fx.getRepository().update(l_Result.value());

    auto l_Result2 = l_Fx.getRepository().getByGroupName("Evening 1");

    ASSERT_TRUE(l_Result2.has_value());
    ASSERT_TRUE(!l_Result2.value().getGroupName().compare("Evening 1"));
}

TEST(GroupRepositoryTests, canAddGroup)
{
    GroupDAO l_Group("Night");

    GroupFixture  l_Fx;
    l_Fx.getRepository().insert(l_Group);

    auto l_Result = l_Fx.getRepository().getByGroupName("Night");

    ASSERT_TRUE(l_Result.has_value());
    ASSERT_TRUE(!l_Result.value().getGroupName().compare("Night"));
}