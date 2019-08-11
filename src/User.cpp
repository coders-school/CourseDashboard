#include<User.hpp>

void User::printUserdata()
{
    std::cout << name << " " << surname << " " << discord << " " << github << " " << firecode << std::endl;
}

void User::deleteUser()
{
    name = "";
    surname = "";
    discord = "";
    github = "";
    firecode = "";
}

void User::changeData(std::string a, std::string b, std::string c, std::string d, std::string e)
{
    name = a;
    surname = b;
    discord = c;
    github = d;   
    firecode = e;
}
