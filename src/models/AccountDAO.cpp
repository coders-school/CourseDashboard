

#include "AccountDAO.hpp"


AccountDAO::AccountDAO(
    const String& email,
    const ID& profileID,
    const ID& id)
    : m_Email(email),
    m_ProfileID(profileID),
    m_ID(id)
{}

//---------------------------------------------------------------------------------------

String AccountDAO::toString() const {

    return "ID: " + std::to_string(m_ID) + 
           "\nProfileID: " + std::to_string(m_ProfileID) +
           "\nEmail: " + m_Email +
           "\n";
}

//---------------------------------------------------------------------------------------

const ID& AccountDAO::getID() const {
    return m_ID; 
}

//---------------------------------------------------------------------------------------

const ID& AccountDAO::getProfileID() const {
    return m_ProfileID; 
}

//---------------------------------------------------------------------------------------

const String& AccountDAO::getEmail() const {
    return m_Email; 
}

//---------------------------------------------------------------------------------------

void AccountDAO::setID(const ID& id) {
    m_ID = id; 
}

//---------------------------------------------------------------------------------------

void AccountDAO::setProfileID(const ID& studentID) {
    m_ProfileID = studentID; 
}

//---------------------------------------------------------------------------------------

void AccountDAO::setEmail(const String& email) {
    m_Email = email; 
}
