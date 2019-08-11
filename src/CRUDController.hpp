#pragma once

#include <string>

#include "repository/UnitOfWork.hpp"

class CRUDController
{
protected:
    UnitOfWork m_UnitOfWork;

public:
    CRUDController() = default;
    ~CRUDController() = default;

    std::string search(const std::string&  searchphrase);

    std::string add(std::string name,
        std::string email,
        std::string discordNick,
        std::string gitHubLink,
        std::string firecodeLink,
        std::string group);

    std::string remove(std::string email);

    std::string update(std::string oldEmail,
        std::string name,
        std::string newEmail,
        std::string discordNick,
        std::string gitHubLink,
        std::string firecodeLink,
        std::string group);

private:
    std::string findByEmail(std::string email);

    std::string findByName(std::string name);

};

