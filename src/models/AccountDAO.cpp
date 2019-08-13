

#include "AccountDAO.hpp"


AccountDAO::AccountDAO(
    const String& email,
    const ID& profileID,
    const ID& id)
    : m_ID(id),
    m_ProfileID(profileID),
    m_Email(email)
{}

//---------------------------------------------------------------------------------------

String AccountDAO::toString() const {

    return "Email: " + m_Email + "\n";
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
