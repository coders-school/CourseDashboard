#pragma once

#include <optional>
#include <string>

#include "../../models/GroupDAO.hpp"

struct IGroupRepository 
{
    virtual std::optional<GroupDAO> getByGroupName(const String& name) const = 0;

//---------------------------------------------------------------------------------------
};