#include <gtest/gtest.h>
#include <utility>

#include "models/ProfileDAO.hpp"

TEST(ProfileDAOTests, canConstructProfile)
{
    ProfileDAO st;
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canConstructProfileParametrized)
{
    ProfileDAO l_ProfileDAO("Joanna", "ArK", "https://github.com", "https://www.firecode.io", 1, 10);
    
    ASSERT_TRUE(l_ProfileDAO.getID() == 10);
    ASSERT_TRUE(!l_ProfileDAO.getName().compare("Joanna"));
    ASSERT_TRUE(!l_ProfileDAO.getDiscordNick().compare("ArK"));
    ASSERT_TRUE(!l_ProfileDAO.getGitHubLink().compare("https://github.com"));
    ASSERT_TRUE(!l_ProfileDAO.getFirecodeLink().compare("https://www.firecode.io"));
    ASSERT_TRUE(l_ProfileDAO.getGroupID() == 1);
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canConstructProfileByCopy)
{
    ProfileDAO l_ProfileDAOToByCopy("Joanna", "ArK", "https://github.com", "https://www.firecode.io", 1, 10);
    ProfileDAO l_ProfileDAO(l_ProfileDAOToByCopy);

    ASSERT_TRUE(l_ProfileDAO.getID() == 10);
    ASSERT_TRUE(!l_ProfileDAO.getName().compare("Joanna"));
    ASSERT_TRUE(!l_ProfileDAO.getDiscordNick().compare("ArK"));
    ASSERT_TRUE(!l_ProfileDAO.getGitHubLink().compare("https://github.com"));
    ASSERT_TRUE(!l_ProfileDAO.getFirecodeLink().compare("https://www.firecode.io"));
    ASSERT_TRUE(l_ProfileDAO.getGroupID() == 1);
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canAssignProfileByCopy)
{
    ProfileDAO l_ProfileDAOToByCopy("Joanna", "ArK", "https://github.com", "https://www.firecode.io", 1, 10);
    ProfileDAO l_ProfileDAO = l_ProfileDAOToByCopy;

    ASSERT_TRUE(l_ProfileDAO.getID() == 10);
    ASSERT_TRUE(!l_ProfileDAO.getName().compare("Joanna"));
    ASSERT_TRUE(!l_ProfileDAO.getDiscordNick().compare("ArK"));
    ASSERT_TRUE(!l_ProfileDAO.getGitHubLink().compare("https://github.com"));
    ASSERT_TRUE(!l_ProfileDAO.getFirecodeLink().compare("https://www.firecode.io"));
    ASSERT_TRUE(l_ProfileDAO.getGroupID() == 1);
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canConvertToString)
{
    ProfileDAO l_Profile("Joanna", "ArK", "https://github.com", "https://www.firecode.io", 1, 10);

    ASSERT_TRUE(l_Profile.toString().find("https://github.com") != std::string::npos);
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetID)
{
    unsigned int id = 10;

    ProfileDAO st;
    st.setID(id);
    ASSERT_TRUE(st.getID() == id);
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetName)
{
    std::string name = "Kamil";

    ProfileDAO st;
    st.setName(name);
    ASSERT_TRUE(!st.getName().compare(name));
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetNick)
{
    std::string nick = "dd";

    ProfileDAO st;
    st.setDiscordNick(nick);
    ASSERT_TRUE(!st.getDiscordNick().compare(nick));

}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetGithub)
{
    std::string gitHubLink = "https://github.com/darkassazi/";
    std::string firecodeLink = "https://www.firecode.io/pages/profile/35190";

    ProfileDAO st;
    st.setGitHubLink(gitHubLink);
    ASSERT_TRUE(!st.getGitHubLink().compare(gitHubLink));
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetFirecodeLink)
{
    std::string firecodeLink = "https://www.firecode.io/pages/profile/35190";



    ProfileDAO st;
    st.setFirecodeLink(firecodeLink);
    ASSERT_TRUE(!st.getFirecodeLink().compare(firecodeLink));
}

//---------------------------------------------------------------------------------------

TEST(ProfileDAOTests, canGetSetGroupID)
{
    unsigned int gid = 1;

    ProfileDAO st;
    st.setGroupID(gid);
    ASSERT_TRUE(st.getGroupID() == gid);
}