#pragma once
#include <iostream>
#include <vector>

class User
{
    public:
    // Constructors
    User(){};    
    User(std::string name, std::string surname, std::string discord, std::string github):
    name(name), surname(surname), discord(discord), github(github) {}
    User(std::vector<std::string> wek)
    {
        name = wek[0];
        surname = wek[1];
        discord = wek[2];
        github = wek[3];
    }

    // Members
    std::string name;
    std::string surname;
    std::string discord;
    std::string github;

    // Methods
    // --> print user data
    void printUserdata();
    // --> delete user
    void deleteUser();
    // --> change user data
    void changeData(std::string a, std::string b, std::string c, std::string d);
    
    // Destructor
    ~User(){};

};
