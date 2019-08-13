#pragma once

#include <algorithm>

#include "Interface/IRepository.hpp"
#include "CDExceptions.hpp"

template<class DAO>
class RepositoryImpl : public IRepository<DAO>
{
protected:
    std::vector<DAO> m_Context;

//---------------------------------------------------------------------------------------

    auto byID(const ID& id) const
    {
        return [&id](const auto& entity) {
            return entity.getID() == id;
        };
    }

//---------------------------------------------------------------------------------------

    template<class TPredicate>
    auto findBy(const TPredicate& predicate) const {
        return std::find_if(m_Context.begin(), m_Context.end(), predicate);
    }

public:
    RepositoryImpl() = default;

 //---------------------------------------------------------------------------------------

    RepositoryImpl(const std::vector<DAO>& context) 
    : m_Context(context) 
    {}

//---------------------------------------------------------------------------------------

    ~RepositoryImpl() = default;

//---------------------------------------------------------------------------------------

    DAO getByID(const ID& id) const override {
        return *findBy(byID(id));
    };

//---------------------------------------------------------------------------------------

    std::vector<DAO> getAll() const override {
        return m_Context;
    };

//---------------------------------------------------------------------------------------

    void remove(const DAO& entity) override
    {
        remove(entity.getID());
    };

//---------------------------------------------------------------------------------------

    void remove(const ID& id) override
    {
        auto l_Result = findBy(byID(id));
        if(l_Result == m_Context.end()) {
            throw NoSuchUserException("User do not exist or has been removed");
        }

        m_Context.erase(l_Result);
    }

//---------------------------------------------------------------------------------------

    void update(const DAO& entity) override
    {
        auto l_Result = std::find_if(m_Context.begin(),
                                     m_Context.end(), 
                                     byID(entity.getID()));

        *l_Result = entity;

    }

//---------------------------------------------------------------------------------------

    std::size_t getLastID() override {
        return m_Context.size();
    }
};
