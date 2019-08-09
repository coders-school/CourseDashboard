#include "User.hpp"
#include <iostream>

User::User(     const std::string & name,
                const std::string & nick,
                const std::string & group,
                const std::string & gitHub,
                const std::string & firecode)
    
    : name_(name)
    , nick_(nick)
    , group_(group)
    , gitHub_(gitHub)
    , firecode_(firecode)
{}

std::string User::getAllInfo() const{
    std::stringstream ss;
    ss<<std::left;   
    ss<<std::setw(1) << "1." << name_ <<"|";
    ss<<std::setw(1) << "2." << nick_ <<"|";
    ss<<std::setw(1) << "3." << group_ <<"|";
    ss<<std::setw(1) << "4." << gitHub_ <<"|";
    ss<<std::setw(1) << "5." << firecode_<<"|";
    ss<<std::endl;
    std::cout<< ss.str();
    return ss.str();
}

void User::updateUser(){
    unsigned int number;
    getAllInfo();
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        std::cin >> name_;
        break;
    case 2:
        std::cout << "Give new value to data: ";
        std::cin >> nick_;
        break;
    case 3:
        std::cout << "Give new value to data: ";
        std::cin >> group_;
        break;
    case 4:
        std::cout << "Give new value to data: ";
        std::cin >> gitHub_;
        break;
    case 5:
        std::cout << "Give new value to data: ";
        std::cin >> firecode_;
        break;
    default:
        std::cout << "You gave wrong value.";
        break;
    }
}

void User::deleteUser(User user){
    v.erase(user);
}

void User::getAllInfoEveryone(const std::vector<User> & v){
    for(const auto& element : v)
    {
        element.getAllInfo();
        std::cout << '\n';
    }
}

void addUser(const User &  User){
    v.emplace_back(User);
}
