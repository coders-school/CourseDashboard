#pragma once

#include <vector>
#include <optional>
#include <variant>

#include "RepositoryImpl.hpp"
#include "Interface/IAccountRepository.hpp"
#include "../models/AccountDAO.hpp"

class AccountRepositoryImpl : public  RepositoryImpl<AccountDAO>, public IAccountRepository
{
private:

    auto byEmail(const String& email) const;

//---------------------------------------------------------------------------------------

    auto byStudentID(const ID& id) const;

//---------------------------------------------------------------------------------------

public:

    AccountRepositoryImpl() {};

//---------------------------------------------------------------------------------------

    AccountRepositoryImpl(const std::vector<AccountDAO>& database)
        : RepositoryImpl(database)
    {};

//---------------------------------------------------------------------------------------

    ~AccountRepositoryImpl()= default;

//---------------------------------------------------------------------------------------

    std::optional<AccountDAO> getByEmail(const String& email) const override;

//---------------------------------------------------------------------------------------

    AccountDAO getByStudentID(const ID& id) const override;

//---------------------------------------------------------------------------------------

    void insert(const AccountDAO& entity) override;

 //--------------------------------------------------------------------------------------- 

    void execute() override;
};
