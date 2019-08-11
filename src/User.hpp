#pragma once
#include <iostream>
#include <vector>

class User
{
    public:
    // Constructors
    User(){};    
    User(std::string name, std::string surname, std::string discord, std::string github, std::string firecode):
    name(name), surname(surname), discord(discord), github(github), firecode(firecode) {}
    User(std::vector<std::string> wek)
    {
        name = wek[0];
        surname = wek[1];
        discord = wek[2];
        github = wek[3];
        firecode = wek[4];
    }

    // Members
    std::string name;
    std::string surname;
    std::string discord;
    std::string github;
    std::string firecode;

    // Methods
    // --> print user data
    void printUserdata();
    // --> delete user
    void deleteUser();
    // --> change user data
    void changeData(std::string a, std::string b, std::string c, std::string d, std::string e);
    
    // Destructor
    ~User(){};

};
