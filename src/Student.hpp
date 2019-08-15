#pragma once
#include <string>
#include <vector>


class Student
{
private:
    std::string name, code, nick, gitHub, firecode;

public:
    Student();
    Student(std::string, std::string, std::string, std::string);
    Student(const Student &);
    void setName (std::string);
    void setNick (std::string);
    void setGitHub (std::string);
    void setFirecode (std::string);
    std::string getName () const;
    std::string getNick () const;
    std::string getGitHub () const;
    std::string getFirecode () const;
   // void show();

};