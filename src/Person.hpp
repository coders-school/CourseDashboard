#pragma once
#include <string>

class Person
{
private:
    std::string name, surname, nick, gitHub, firecode;

public:
    Person();
    Person(std::string, std::string, std::string, std::string, std::string);
    Person(const Person &);
    void setName (std::string);
    void setSurname (std::string);
    void setNick (std::string);
    void setGitHub (std::string);
    void setFirecode (std::string);
    std::string getName () const;
    std::string getSurname () const;
    std::string getNick () const;
    std::string getGitHub () const;
    std::string getFirecode () const;
};