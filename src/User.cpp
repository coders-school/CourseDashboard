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
    ss<<std::setw(10) << name_ <<"|";
    ss<<std::setw(10) << nick_ <<"|";
    ss<<std::setw(15) << group_ <<"|";
    ss<<std::setw(20) << gitHub_ <<"|";
    ss<<std::setw(20) << firecode_<<"|";
    ss<<std::endl;
    return ss.str();
}

void User::updateUser(User user){
    unsigned int number;
    auto newValue;
    getAllInfo(user);
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        std::cin >> user.name_;
        break;
    case 2:
        std::cout << "Give new value to data: ";
        std::cin >> user.nick_;
        break;
    case 3:
        std::cout << "Give new value to data: ";
        std::cin >> user.group_;
        break;
    case 4:
        std::cout << "Give new value to data: ";
        std::cin >> user.gitHub_;
        break;
    case 5:
        std::cout << "Give new value to data: ";
        std::cin >> user.firecode_;
        break;
    default:
        std::cout << "You gave wrong value."
        break;
    }
}

void User::deleteUser(User user){
    //dokończę jutro, utworzę vector<User> który będzie przechowywał obiekty więc usunięcie będzie
    //usuwało dany element vectora a dodanie będzie przez np. emplace_back
}
