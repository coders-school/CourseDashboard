#include "Student.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Student::Student(){
    name = "x";
    nick = "y";
    gitHub = "none";
    firecode = "none";
}

Student::Student(std::string StudentNick, 
                 std::string StudentName, 
                 std::string gitHubNick, 
                 std::string firecodeNick) {
   // static unsigned int id = 0;
    this -> nick = StudentNick;
    this -> name = StudentName;
    this -> gitHub = gitHubNick;
    this -> firecode = firecodeNick;
}

Student::Student(const Student &obj){
    name = obj.name;
    nick = obj.nick;
    gitHub = obj.gitHub;
    firecode = obj.firecode;
}

void Student::setName (std::string StudentName){
    this -> name = StudentName;
}
void Student::setNick (std::string StudentNick){
    this -> nick = StudentNick;
}
void Student::setGitHub(std::string gitHubNick){
    this -> gitHub = gitHubNick;
}
void Student::setFirecode (std::string firecodeNick){
    this -> nick = firecodeNick;
}

std::string  Student::getName()const{
    return name;
}
std::string  Student::getNick()const{
    return nick;
}
std::string Student::getGitHub()const{
    return gitHub;
}
std::string Student::getFirecode()const{
    return firecode;
}
/*
void Student::show(){
    std::cout << ">>\n" << " imie: " << this -> name << 
                           " nick: " << this -> nick <<
                           " GitHub: "<< this -> gitHub << 
                           " Firecode: " << this -> firecode << std::endl; "<<<<\n\n";
}
*/