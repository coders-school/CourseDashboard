
#include "AccountRepositoryImpl.hpp"
#include "../CDExceptions.hpp"


auto AccountRepositoryImpl::byEmail(const String& email) const
{
    return [&email](const auto& account) {
        return !account.getEmail().compare(email);
    };
}

//---------------------------------------------------------------------------------------

auto AccountRepositoryImpl::byStudentID(const ID& id) const
{
    return [&id](const auto& account) {
        return account.getProfileID() == id;
    };
}

//---------------------------------------------------------------------------------------


std::optional<AccountDAO> AccountRepositoryImpl::getByEmail(const String& email) const
{
    auto l_Result = findBy(byEmail(email));
    
    if (l_Result == m_Context.end()) {
        return std::nullopt;
    }

    return std::optional<AccountDAO>(*l_Result);
}

//---------------------------------------------------------------------------------------

AccountDAO AccountRepositoryImpl::getByStudentID(const ID& id) const
{
    auto l_Result = findBy(byStudentID(id));
    return *l_Result;
}

//---------------------------------------------------------------------------------------

void AccountRepositoryImpl::insert(const AccountDAO& entity)
{
    auto l_Result = findBy(byEmail(entity.getEmail()));
    if(l_Result != m_Context.end()) {
        throw UniqueEntryException("User with the email " + entity.getEmail() + " is already registered");
    }

    AccountDAO l_AccountDAO(entity);
    l_AccountDAO.setID(m_Context.size() + 1);
    m_Context.push_back(l_AccountDAO);
}

//---------------------------------------------------------------------------------------

void AccountRepositoryImpl::execute() {
    //TODO:: To be implemented in user story 2
};
