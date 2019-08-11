#include "ModifyCoders.hpp"
#include <algorithm>


void ModifyCoders::addUser(const Coders& tmpUser)
{
    codersLibrary.push_back(tmpUser);
}
void ModifyCoders::printUser(Coders tmpUser)
{
    std::cout << "---------------------" << std::endl;
    tmpUser.printUserData();
}
void ModifyCoders::printEveryone()
{
    for (const auto& elements : codersLibrary)
    {
        printUser(elements);
        std::cout << std::endl;
    }
}
void ModifyCoders::deleteUser(Coders& tmpUser)
{
    auto it = std::remove_if(codersLibrary.begin(), codersLibrary.end(), [&](auto test)
    {
        return tmpUser==test;
    });
    codersLibrary.erase(it, codersLibrary.end());
}
