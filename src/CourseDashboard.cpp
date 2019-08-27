#include "CourseDashboard.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <fstream>

CourseDashboard::CourseDashboard() {}

void CourseDashboard::showAll()
{
    for (auto & user : users_)
    {
        std::cout << user.getAllInfo();
    }
}

void CourseDashboard::createUser(const User & user)
{
    users_.emplace_back(user);
}

void CourseDashboard::deleteUserByNick(std::string nick)
{  
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });

    if (it != std::end(users_))
    {
        users_.erase(it);
    }
}

void CourseDashboard::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });
    
    if (it != std::end(users_))
    {
        std::cout << it->getAllInfo();
    }
}

void CourseDashboard::updateUser(User & user)
{
    unsigned int number;
    std::cout << user.getAllInfo();
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    std::string name, nick, group, gitHub, firecode;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        std::cin >> name;
        user.setName(name);
        break;
    case 2:
        std::cout << "Give new value to data: ";
        std::cin >> nick;
        user.setNick(nick);
        break;
    case 3:
        std::cout << "Give new value to data: ";
        std::cin >> group;
        user.setGroup(group);
        break;
    case 4:
        std::cout << "Give new value to data: ";
        std::cin >> gitHub;
        user.setGitHub(gitHub);
        break;
    case 5:
        std::cout << "Give new value to data: ";
        std::cin >> firecode;
        user.setFirecode(firecode);
        break;
    default:
        std::cout << "You gave wrong value.";
        break;
    }
}

std::string CourseDashboard::eMail()
{
        std::string email;
        std::cout<<"Please enter a email."<<std::endl;
        std::cin>>email;
        std::cout << "e-mail: \"" << email<< "\"\n";

    return email;
}

std::string CourseDashboard::passWord()
{
	std::string password1, password2;
	std::cout << "Please enter your password." << std::endl;
	std::cin >> password1;
	std::cout << "Please re-enter your password." << std::endl;
	std::cin >> password2;

	while (password1 != password2)
	{
		std::cout << "Error! Passwords do not match." "\n";
		std::cout << "Please enter your password." << std::endl;
		std::cin >> password1;
		std::cout << "Please re-enter your password." << std::endl;
		std::cin >> password2;
	}

    return password1; 
}

void CourseDashboard::logIn()
{
    std::string emailKeyword = eMail();
    std::string passwordKeyword = passWord();
    std::string email, password;
    std::string line;
    std::fstream file;
    file.open("plik.txt", std::ios::in);

    if(!file.good())
    {
        std::cout<<"file doesn't exist";
        exit(0);
    }

    while(!file.eof())
    {
        file>>email;
        file>>password;

        if(emailKeyword == email && passwordKeyword == password) 
        {   
            std::cout << "Login succeesful!" << std::endl; 
            break;
        }
        else
        {
            std::cout << "Incorrect e-mail or password!" << std::endl; 
            break;
        }
    }
    file.close();
}
