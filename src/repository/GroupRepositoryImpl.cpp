

#include "GroupRepositoryImpl.hpp"
#include "CDExceptions.hpp"

auto GroupRepositoryImpl::byGroupName(const String& groupName) const
{
    return [&groupName](const auto& group)
    {
        bool res = !group.getGroupName().compare(groupName);
        return !group.getGroupName().compare(groupName);
    };
}

//---------------------------------------------------------------------------------------

std::optional<GroupDAO> GroupRepositoryImpl::getByGroupName(const String& groupName) const
{
    auto l_Result = findBy(byGroupName(groupName));

    if(l_Result == m_Context.end()) {
        return std::nullopt;
    }

    return std::optional<GroupDAO>(*l_Result);
}

//---------------------------------------------------------------------------------------

void GroupRepositoryImpl::insert(const GroupDAO& entity)
{
    GroupDAO e(entity);
    e.setID(m_Context.size() + 1 );
    m_Context.push_back(e);
}

//---------------------------------------------------------------------------------------

void GroupRepositoryImpl::execute() {
    //TODO:: To be implemented in user story 2
}

