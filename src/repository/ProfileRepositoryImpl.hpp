#pragma once

#include <variant>
#include <string>

#include "RepositoryImpl.hpp"
#include "Interface/IProfileRepository.hpp"
#include "../models/ProfileDAO.hpp"



class ProfileRepositoryImpl : public RepositoryImpl<ProfileDAO>, public IProfileRepository {

private:

    auto byName(const String& name) const;

//---------------------------------------------------------------------------------------

    auto byNick(const String& nick) const;

//---------------------------------------------------------------------------------------

    auto byGroup(const ID& groupID) const;

//---------------------------------------------------------------------------------------

    template<class UnaryPredicate>
    auto findUsers(UnaryPredicate unaryPredicate)  const
    {
        std::vector<ProfileDAO> l_Result;
        std::copy_if(m_Context.begin(), m_Context.end(), std::back_inserter(l_Result), unaryPredicate);
        
        if (l_Result.size() == 0) {
            return std::optional<std::vector<ProfileDAO>>();
        }

        return std::optional<std::vector<ProfileDAO>>(l_Result);
    }

public:
    ProfileRepositoryImpl() = default;

//---------------------------------------------------------------------------------------

    ProfileRepositoryImpl(std::vector<ProfileDAO> database)
        : RepositoryImpl(database)
    {}

//---------------------------------------------------------------------------------------

    Profiles getByName(const String& email) const override;

//---------------------------------------------------------------------------------------

    Profiles getByNick(const String& discordusername) const override;

//---------------------------------------------------------------------------------------

    Profiles getByGroup(const ID& group) const override;

//---------------------------------------------------------------------------------------

    void insert(const ProfileDAO& entity) override;

//---------------------------------------------------------------------------------------

    void execute() override;


};