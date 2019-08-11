
#include <string>

#include "CRUDController.hpp"
#include "CRUDValidation.hpp"

std::string CRUDController::search(const std::string&  searchphrase)
{

    if (crud::validateEmail(searchphrase))
    {
        return findByEmail(searchphrase);
    }
    else if (crud::validateName(searchphrase))
    {
        return findByName(searchphrase);

    }
    return "CD002";
}

//---------------------------------------------------------------------------------------

std::string CRUDController::add(
    std::string name,
    std::string email,
    std::string discordNick,
    std::string gitHubLink,
    std::string firecodeLink,
    std::string group)
{
    auto l_Group  = m_UnitOfWork.getGroupRepository().getByGroupName(group);
    if (!l_Group.has_value()) {
        return "CD003";
    };

    auto l_AccountTest = m_UnitOfWork.getAccountRepository().getByEmail(email);
    if (l_AccountTest.has_value()) {
        return "CD004";
    }

    ProfileDAO l_Profile(name, discordNick, gitHubLink, firecodeLink, l_Group.value().getID());
    m_UnitOfWork.getProfileRepository().insert(l_Profile);
    auto l_ProfileID = m_UnitOfWork.getProfileRepository().getLastID();

    AccountDAO l_Account(email, l_ProfileID);
    m_UnitOfWork.getAccountRepository().insert(l_Account);


    return "Successfully added user " + name;
}

//---------------------------------------------------------------------------------------

std::string CRUDController::remove(std::string email)
{
    if (!crud::validateEmail(email)) {
        return "CD005";
    }

    auto l_Account = m_UnitOfWork.getAccountRepository().getByEmail(email);
    if (!l_Account.has_value()) {
        return "CD001";
    }

    auto l_Profile = m_UnitOfWork.getProfileRepository()
        .getByID(l_Account.value().getProfileID());

    m_UnitOfWork.getAccountRepository().remove(l_Account.value());
    m_UnitOfWork.getProfileRepository().remove(l_Profile);

    return "Successfully deleted User " + email;

}

//---------------------------------------------------------------------------------------

std::string CRUDController::update(
    std::string oldEmail,
    std::string newName,
    std::string newEmail,
    std::string newDiscordNick,
    std::string newGitHubLink,
    std::string newFirecodeLink,
    std::string newGroup)
{
    if (!crud::validateEmail(oldEmail)) {
        return "CD005";
    }

    auto l_Account = m_UnitOfWork.getAccountRepository().getByEmail(oldEmail);
    if (!l_Account.has_value()) {
        return "CD001";
    }

    auto l_NewGroup = m_UnitOfWork.getGroupRepository().getByGroupName(newGroup);
    if (!l_NewGroup.has_value()) {
        return "CD003";
    }

    auto l_Profile = m_UnitOfWork.getProfileRepository()
        .getByID(l_Account.value().getProfileID());

    
    l_Account.value().setEmail(newEmail);

    l_Profile.setName(newName);
    l_Profile.setName(newEmail);
    l_Profile.setName(newDiscordNick);
    l_Profile.setName(newGitHubLink);
    l_Profile.setGroupID(l_NewGroup.value().getID());


    m_UnitOfWork.getAccountRepository().update(l_Account.value());
    m_UnitOfWork.getProfileRepository().update(l_Profile);

    return "Successfully Updated User data";

}

//---------------------------------------------------------------------------------------

std::string CRUDController::findByEmail(std::string email)
{
    auto l_Account = m_UnitOfWork.getAccountRepository().getByEmail(email);

    if (!l_Account.has_value()) {
        return "CD001";
    }


    auto l_Profile = m_UnitOfWork.getProfileRepository()
                                 .getByID(l_Account.value()
                                 .getProfileID());

    auto l_Group = m_UnitOfWork.getGroupRepository().getByID(l_Profile.getGroupID());

    std::string l_Result = l_Account.value().toString() 
                         + l_Profile.toString() 
                         + l_Group.toString();

    return l_Result;
}

//---------------------------------------------------------------------------------------

std::string CRUDController::findByName(std::string name)
{
    auto l_Profile = m_UnitOfWork.getProfileRepository().getByName(name);

    if (!l_Profile.has_value()) {
        return "CD001";
    }


    std::string l_Result = "";
    for (auto p : l_Profile.value()) {
        auto l_Group = m_UnitOfWork.getGroupRepository().getByID(p.getGroupID());
        auto l_Account = m_UnitOfWork.getAccountRepository().getByStudentID(p.getID());

        std::string l_IntResult = l_Account.toString() + p.toString() + l_Group.toString();
        l_Result += l_IntResult + "\n\n";
    }

    return l_Result;
}
