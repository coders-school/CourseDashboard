#pragma once

#include "IDAO.hpp"

class ProfileDAO
{
    ID m_ID = 0;              //[UNIQUE, NOT NULL]
    ID m_GroupID = 0;         //[NOT NULL]
    String m_name = "";            //[NOT NULL]
    String m_DiscordNick = "";     //[NOT NULL]
    String m_GitHubLink = "";      //[UNIQUE, NOT NULL]
    String m_FirecodeLink = "";    //[UNIQUE, NOT NULL]
    
public:

    ProfileDAO() = default;

//---------------------------------------------------------------------------------------

    ProfileDAO(const String& name,
        const String& nick,
        const String& gitHubLink,
        const String& firecodeLink,
        const ID& groupID,
        const ID& id = 0);

//---------------------------------------------------------------------------------------

    ProfileDAO(const ProfileDAO& other) = default;

//---------------------------------------------------------------------------------------

    ~ProfileDAO() = default;

//---------------------------------------------------------------------------------------

    ProfileDAO& operator=(const ProfileDAO& other) = default;

//---------------------------------------------------------------------------------------

    String toString();

//---------------------------------------------------------------------------------------

    const ID& getID() const;

//---------------------------------------------------------------------------------------

    const String& getName() const;

//---------------------------------------------------------------------------------------

    const String& getDiscordNick() const;

//---------------------------------------------------------------------------------------

    const String& getGitHubLink() const;

//---------------------------------------------------------------------------------------

    const String& getFirecodeLink() const;

//---------------------------------------------------------------------------------------

    const ID& getGroupID() const;
    
//---------------------------------------------------------------------------------------

    void setID(const ID& id);

//---------------------------------------------------------------------------------------

    void setName(const String& name);

//---------------------------------------------------------------------------------------

    void setDiscordNick(const String& nick);

//---------------------------------------------------------------------------------------

    void setGitHubLink(const String& gitHubLink);

//---------------------------------------------------------------------------------------

    void setFirecodeLink(const String& firecodeLink);

//---------------------------------------------------------------------------------------

    void setGroupID(const ID& groupID);
};
