
#include <utility>

#include "ProfileDAO.hpp"



ProfileDAO::ProfileDAO(const String& name,
            const String& nick,
            const String& gitHubLink,
            const String& firecodeLink,
            const ID& groupID, 
            const ID& id)
            : m_ID(id),
            m_name(name),
            m_DiscordNick(nick),
            m_GitHubLink(gitHubLink),
            m_FirecodeLink(firecodeLink),
            m_GroupID(groupID)
{}

//---------------------------------------------------------------------------------------

String ProfileDAO::toString() {

    return "ID: " + std::to_string(m_ID) +
           "\nGroupID: " + std::to_string(m_GroupID) +
           "\nName: " + m_name +
           "\nDiscord Nick: " + m_DiscordNick +
           "\nGithub Link: " + m_GitHubLink +
           "\nFirecode Link: " + m_FirecodeLink + 
           "\n";
}

//---------------------------------------------------------------------------------------

const ID& ProfileDAO::getID() const {
    return m_ID; 
}

//---------------------------------------------------------------------------------------

const String& ProfileDAO::getName() const {
    return m_name; 
}

//---------------------------------------------------------------------------------------

const String& ProfileDAO::getDiscordNick() const {
    return m_DiscordNick; 
}

//---------------------------------------------------------------------------------------

const String& ProfileDAO::getGitHubLink() const {
    return m_GitHubLink; 
}

//---------------------------------------------------------------------------------------

const String& ProfileDAO::getFirecodeLink() const {
    return m_FirecodeLink; 
}

//---------------------------------------------------------------------------------------

const ID& ProfileDAO::getGroupID() const {
    return m_GroupID; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setID(const ID& id) {
    m_ID = id; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setName(const String& name) {
    m_name = name; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setDiscordNick(const String& nick) {
    m_DiscordNick = nick; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setGitHubLink(const String& gitHubLink) {
    m_GitHubLink = gitHubLink; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setFirecodeLink(const String& firecodeLink) {
    m_FirecodeLink = firecodeLink; 
}

//---------------------------------------------------------------------------------------

void ProfileDAO::setGroupID(const ID& groupID) {
    m_GroupID = groupID; 
}
