#pragma once

#include "CRUDController.hpp"
#include "repository/UnitOfWork.hpp"

class UnitOfWorkFx : public UnitOfWork
{
public:
    UnitOfWorkFx()
    {
        std::vector<AccountDAO> m_AccountTable = {
            AccountDAO("kamil.waszkiewicz.2@gmail.com", 1,  1),
            AccountDAO("0king.pp1115@chaonamdinh.com",  2,  2),
            AccountDAO("fanjel.a@surat.ddnsfree.com",   3,  3),
            AccountDAO("9ayoub.geoc@design-42.ru",      4,  4),
        };

        AccountRepositoryImpl l_AccountRepository(m_AccountTable);
        m_AccountRepository = l_AccountRepository;



        std::vector<GroupDAO> m_GroupTable = {
            GroupDAO("Weekend", 1),
            GroupDAO("Evening", 2)
        };

        GroupRepositoryImpl l_GroupRepository(m_GroupTable);
        m_GroupRepository = l_GroupRepository;



        std::vector<ProfileDAO> m_ProfileTable = {
            ProfileDAO("Kamil",     "kamil.waszkiewicz",    "https://github.com",   "https://www.firecode.io",   1,  1),
            ProfileDAO("Tester1",   "0king.pp1115",         "https://github.com",   "https://www.firecode.io",   1,  2),
            ProfileDAO("Kamil",    "fanjel",               "https://github.com",   "https://www.firecode.io",   2,  3),
            ProfileDAO("Tester3",   "9ayoub",               "https://github.com",   "https://www.firecode.io",   2,  4),
        };

        ProfileRepositoryImpl l_ProfileRepository(m_ProfileTable);
        m_ProfileRepository = l_ProfileRepository;
    };
};

//---------------------------------------------------------------------------------------

class CRUDControllerFx : public CRUDController
{
public:
    CRUDControllerFx()
    {
        UnitOfWorkFx l_UnitOfWorkFx;
        m_UnitOfWork = l_UnitOfWorkFx;
    }

private:

};

