#pragma once

#include <vector>
#include <variant>
#include <optional>

#include "models/IDAO.hpp"

template<class DAO>
struct IRepository
{
    
    virtual DAO getByID(const ID& id) const = 0;

//---------------------------------------------------------------------------------------
	
    virtual std::vector<DAO> getAll() const = 0;

//---------------------------------------------------------------------------------------

	virtual void remove(const DAO& entity) = 0;

//---------------------------------------------------------------------------------------

    virtual void remove(const ID& id) = 0;

//---------------------------------------------------------------------------------------

	virtual void update(const DAO& entity) = 0;

//---------------------------------------------------------------------------------------

	virtual void insert(const DAO& entity) = 0;
//---------------------------------------------------------------------------------------

	virtual void execute() = 0;

//---------------------------------------------------------------------------------------

    virtual std::size_t getLastID() = 0;

//---------------------------------------------------------------------------------------

    virtual ~IRepository() = default;
};
