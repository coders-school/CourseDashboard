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
 