#pragma once

#include <string>
#include <variant>
#include <optional>

#include "../../models/AccountDAO.hpp"


struct IAccountRepository
{
    virtual std::optional<AccountDAO> getByEmail(const String& email) const = 0;

//---------------------------------------------------------------------------------------

    virtual AccountDAO getByStudentID(const ID& id) const = 0;

//---------------------------------------------------------------------------------------

    virtual ~IAccountRepository() = default;
};
