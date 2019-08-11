#include<User.hpp>

void User::printUserdata()
{
    std::cout << name << " " << surname << " " << discord << " " << github << std::endl;
}

void User::deleteUser()
{
    name = "";
    surname = "";
    discord = "";
    github = "";
}

void User::changeData(std::string a, std::string b, std::string c, std::string d)
{
    name = a;
    surname = b;
    discord = c;
    github = d;   
}
