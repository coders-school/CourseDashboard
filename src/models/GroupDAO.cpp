
#include <utility>

#include "GroupDAO.hpp"

GroupDAO::GroupDAO(const String groupName, const ID& id)
    : m_ID(id), m_GroupName(groupName)
{}

//---------------------------------------------------------------------------------------

String GroupDAO::toString() {
    return "Group: " + m_GroupName + "\n";
}

//---------------------------------------------------------------------------------------

const ID& GroupDAO::getID() const {
    return m_ID; 
}

//---------------------------------------------------------------------------------------

const String& GroupDAO::getGroupName() const {
    return m_GroupName; 
}

//---------------------------------------------------------------------------------------

void GroupDAO::setID(const ID& id) {
    m_ID = id; 
}

//---------------------------------------------------------------------------------------

void GroupDAO::setGroupName(const String& groupName) {
    m_GroupName = groupName; 
}