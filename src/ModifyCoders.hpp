#pragma once
#include "Coders.hpp"
#include <vector>

class ModifyCoders
{
    std::vector<Coders> codersLibrary;
public:
    void addUser(const Coders& tmpUser);
    void printUser(Coders tmpUser);
    void printEveryone();
    void deleteUser(Coders& tmpUser);
};