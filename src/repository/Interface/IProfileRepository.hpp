#pragma once

#include <string>
#include <variant>

#include "../../models/ProfileDAO.hpp"


struct IProfileRepository
{
protected:
    using Profiles = std::optional<std::vector<ProfileDAO>>;

public:
    virtual Profiles getByName(const String& name) const = 0;

//---------------------------------------------------------------------------------------

    virtual Profiles getByNick(const String& discordusername) const = 0;

//---------------------------------------------------------------------------------------

    virtual Profiles getByGroup(const ID& group) const = 0;

//---------------------------------------------------------------------------------------

    virtual ~IProfileRepository() = default;
};
