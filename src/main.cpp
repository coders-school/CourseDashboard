#include <iostream>
#include "CourseDashboard.hpp"
#include "Coders.hpp"
#include <vector>
#include <algorithm>

void printEveryone(const std::vector<Coders>& tmpLibrary);
void printUser(Coders tmpUser);
void addUser(const Coders& tmpUser);
void deleteUser(std::vector<Coders> tmpVec, Coders tmpUser); // WIP

std::vector<Coders> codersLibrary;

int main()
{
    Coders Vandam{"Łukasz", "vandam", "https://github.com/lucaswalicki", "fireVandam", "weekendowa"};
    Coders Ziomeczek{"Sylwia", "TheDude", "gitDude", "fireDude", "weekendowa"};
    printUser(Ziomeczek);
    addUser(Ziomeczek);
    addUser(Vandam);
    printEveryone(codersLibrary);
    std::cout << "Course Dashboard" << std::endl;
    deleteUser(codersLibrary, Vandam); // will not compile now
    return 0;
}

void addUser(const Coders& tmpUser)
{
    codersLibrary.push_back(tmpUser);
}

void printUser(Coders tmpUser)
{
    std::cout << "Name: "; 
    tmpUser.printName(); std::cout << std::endl;
    std::cout << "Group: "; 
    tmpUser.printGroup(); std::cout << std::endl;
    std::cout << "Discord nickname: "; 
    tmpUser.printDiscordNickname(); std::cout << std::endl;
    std::cout << "FireCode link: "; 
    tmpUser.printFirecodeLink(); std::cout << std::endl;
    std::cout << "GitHub link: ";
    tmpUser.printGithubLink(); std::cout << std::endl;
}

void printEveryone(const std::vector<Coders>& tmpLibrary)
{
    for(const auto& elements : tmpLibrary)
    {
        printUser(elements);
        std::cout << std::endl;
    }
}

void deleteUser(std::vector<Coders> tmpVec, Coders tmpUser)
{
    //std::remove_if(tmpVec.begin(), tmpVec.end(), []()
    //{
    //    if()
    //})
}