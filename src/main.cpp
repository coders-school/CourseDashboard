#include <iostream>
#include "CourseDashboard.hpp"
#include "Coders.hpp"
#include <vector>
#include <algorithm>


std::vector<Coders> codersLibrary;

void addUser(const Coders& tmpUser);
void printUser(Coders tmpUser);
void printEveryone(std::vector<Coders> tmpLibrary);
void deleteUser(std::vector<Coders>& tmpVec, Coders& tmpUser);

int main()
{
    std::cout << "Course Dashboard" << std::endl;
    Coders::Group wGroup;
    wGroup = Coders::Group::weekends;
    Coders::Group eGroup;
    eGroup = Coders::Group::evenings;
    Coders Vandam {"Łukasz", "vandam", "https://github.com/lucaswalicki", "fireVandam", wGroup};
    Coders Ziomeczek {"Sylwia", "TheDude", "gitDude", "fireDude", wGroup};
    Coders TestSubject {"Coder", "Enignma", "gitCoder", "fireCoder", eGroup};
    addUser(Ziomeczek);
    addUser(Vandam);
    addUser(TestSubject);
    //deleteUser(codersLibrary, Vandam);
    printEveryone(codersLibrary);
    return 0;
}

void addUser(const Coders& tmpUser)
{
    codersLibrary.push_back(tmpUser);
}

void printUser(Coders tmpUser)
{
    std::cout << "---------------------" << std::endl;
    tmpUser.printUserData();
}

void printEveryone(std::vector<Coders> tmpLibrary)
{
    for (const auto& elements : tmpLibrary)
    {
        printUser(elements);
        std::cout << std::endl;
    }
}

void deleteUser(std::vector<Coders>& tmpVec, Coders& tmpUser)
{
    auto it = std::remove_if(tmpVec.begin(), tmpVec.end(), [&](auto test)
    {
        return tmpUser==test;
    });
    tmpVec.erase(it, tmpVec.end());
}
