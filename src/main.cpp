#include <iostream>
#include "CourseDashboard.hpp"
#include "picosha2.h"
#include "User.hpp"
#include "AuthenticationProvider.hpp"

int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    

    User user1("joanna", "bed", User::Group::evening, "teo", "fire", "email", "12345");
  
    std::cout << user1.getPassword() << std::endl;

    AuthenticationProvider a;
    std::cout << std::boolalpha << a(user1, "email", "5994471abb01112afcc18159f6cc74b4f511b99806da59b3caf5a9c173cacfc5") << std::endl;
 
    cdb.saveToFile("userDatabase.txt");
    cdb.loadFromFile("userDatabase.txt");

    return 0;
}
