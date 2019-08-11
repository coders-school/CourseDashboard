#pragma once

#include <algorithm>

#include "Interface/IRepository.hpp"

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
        return std::find_if(this->m_Context.begin(), this->m_Context.end(), predicate);
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
        return this->m_Context;
    };

//---------------------------------------------------------------------------------------

    void remove(const DAO& entity) override
    {
        this->remove(entity.getID());
    };

//---------------------------------------------------------------------------------------

    void remove(const ID& id) override
    {
        auto l_Result = findBy(byID(id));
        this->m_Context.erase(l_Result);
    }

//---------------------------------------------------------------------------------------

    void update(const DAO& entity) override
    {
        auto l_Result = std::find_if(this->m_Context.begin(),
                                     this->m_Context.end(), 
                                      byID(entity.getID()));
        
        *l_Result = entity;

    }

//---------------------------------------------------------------------------------------

    std::size_t getLastID() override {
        return this->m_Context.size();
    }
};
