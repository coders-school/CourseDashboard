#include <iostream>
#include "CourseDashboard.hpp"
#include "Coders.hpp"
#include <vector>

void printEveryone(std::vector<Coders> tmpLibrary);
void printUser(Coders newUser);
void addUser(Coders newUser);
//void editUser();
//void deleteUser();

std::vector<Coders> codersLibrary;

int main()
{
<<<<<<< HEAD
    //Coders Ziomeczek;
=======
    Coders Ziomeczek;
    Ziomeczek.insertName("Sylwia");
    Ziomeczek.insertGroup("Weekendowa");
    Ziomeczek.insertDiscordNickname("DUUD");
    Ziomeczek.insertFirecodeLink("asdasd");
    Ziomeczek.insertGithubLink("asdasdasd");
    printUser(Ziomeczek);
    addUser(Ziomeczek);
    printEveryone(codersLibrary);
>>>>>>> Working prints
    std::cout << "Course Dashboard" << std::endl;
    return 0;
}

void addUser(Coders newUser)
{
    codersLibrary.push_back(newUser);
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

void printEveryone(std::vector<Coders> tmpLibrary)
{
    for(auto elements : tmpLibrary)
    {
        printUser(elements);
    }
}