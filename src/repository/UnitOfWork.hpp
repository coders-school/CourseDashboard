#pragma once

#include "ProfileRepositoryImpl.hpp"
#include "AccountRepositoryImpl.hpp"
#include "GroupRepositoryImpl.hpp"

class UnitOfWork
{
protected:
    // TODO:: remove vectors when implementinf user story 2;
    std::vector<AccountDAO> m_AccountDatabase;
    std::vector<ProfileDAO> m_ProfileDatabase;
    std::vector<GroupDAO> m_GroupDatabase;

    AccountRepositoryImpl m_AccountRepository;
    ProfileRepositoryImpl m_ProfileRepository;
    GroupRepositoryImpl m_GroupRepository;

public:


    UnitOfWork()
        : m_AccountRepository(m_AccountDatabase), 
          m_ProfileRepository(m_ProfileDatabase), 
          m_GroupRepository(m_GroupDatabase)
    {};

//---------------------------------------------------------------------------------------

	~UnitOfWork() = default;

//---------------------------------------------------------------------------------------

    ProfileRepositoryImpl& getProfileRepository() { 
        return m_ProfileRepository; 
    }

//---------------------------------------------------------------------------------------

    AccountRepositoryImpl& getAccountRepository() { 
        return m_AccountRepository; 
    }

//---------------------------------------------------------------------------------------

    GroupRepositoryImpl& getGroupRepository() { 
        return m_GroupRepository; 
    }
};