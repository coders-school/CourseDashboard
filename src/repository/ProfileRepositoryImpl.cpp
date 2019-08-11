
#include "ProfileRepositoryImpl.hpp"

using Profiles = std::optional<std::vector<ProfileDAO>>;


auto ProfileRepositoryImpl::byName(const String& name) const
{
    return [&name](const auto& student) {
        return !student.getName().compare(name);
    };
}

//---------------------------------------------------------------------------------------

auto ProfileRepositoryImpl::byNick(const String& discordusername) const
{
    return [&discordusername](const auto& student) {
        return !student.getDiscordNick().compare(discordusername);
    };
}

//---------------------------------------------------------------------------------------

auto ProfileRepositoryImpl::byGroup(const ID& groupID) const
{
    return [&groupID](const auto& student) {
        return student.getGroupID() == groupID;
    };
}

//---------------------------------------------------------------------------------------

Profiles ProfileRepositoryImpl::getByName(const String& name)  const {
    return findUsers(byName(name));
}

//---------------------------------------------------------------------------------------

Profiles ProfileRepositoryImpl::getByNick(const String& discordusername) const {
    return findUsers(byNick(discordusername));
}

//---------------------------------------------------------------------------------------

Profiles ProfileRepositoryImpl::getByGroup(const ID& group) const {
    return findUsers(byGroup(group));
}

//---------------------------------------------------------------------------------------

void ProfileRepositoryImpl::insert(const ProfileDAO& entity)
{
    ProfileDAO e = entity;
    e.setID(m_Context.size() + 1);
    m_Context.push_back(e);
}

//---------------------------------------------------------------------------------------

void ProfileRepositoryImpl::execute() {
    //TODO:: To be implemented in user story 2
}
