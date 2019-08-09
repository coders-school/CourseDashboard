#include "Person.hpp"
#include <string>

Person::Person(){
    name = "x";
    surname = "y";
    nick = "z";
    gitHub = "none";
    firecode = "none";
}

Person::Person(std::string personName, std::string personSurname, std::string personNick, 
               std::string gitHubNick, std::string firecodeNick){
    name = personName;
    surname = personSurname;
    nick = personNick;
    gitHub = gitHubNick;
    firecode = firecodeNick;
}

Person::Person(const Person &obj){
    name = obj.name;
    surname = obj.surname;
    nick = obj.nick;
    gitHub = obj.gitHub;
    firecode = obj.firecode;
}

void Person::setName (std::string personName){
    name = personName;
}
void Person::setSurname (std::string personSurname){
    surname = personSurname;
}
void Person::setNick (std::string personNick){
    nick = personNick;
}
void Person::setGitHub(std::string gitHubNick){
    surname = gitHubNick;
}
void Person::setNick (std::string firecodeNick){
    nick = firecodeNick;
}

std::string  Person::getName()const{
    return name;
}
std::string  Person::getSurname()const{
    return surname;
}
std::string  Person::getNick()const{
    return nick;
}
std::string Person::getGitHub()const{
    return gitHub;
}
std::string Person::getNick()const{
    return firecode;
}