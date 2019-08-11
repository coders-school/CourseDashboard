#pragma once

#include "RepositoryImpl.hpp"
#include "../models/GroupDAO.hpp"
#include "Interface/IGroupRepository.hpp"

class GroupRepositoryImpl : public RepositoryImpl<GroupDAO>, public IGroupRepository
{
    auto byGroupName(const String& groupName) const;

public:

    GroupRepositoryImpl() = default;

//---------------------------------------------------------------------------------------

    GroupRepositoryImpl(const std::vector<GroupDAO>& context) : RepositoryImpl(context)
    {}

//---------------------------------------------------------------------------------------

    ~GroupRepositoryImpl() = default;

//---------------------------------------------------------------------------------------

    std::optional<GroupDAO> getByGroupName(const String& groupName) const override;

//---------------------------------------------------------------------------------------

    void insert(const GroupDAO& entity) override;

//---------------------------------------------------------------------------------------

    void execute() override;
};
