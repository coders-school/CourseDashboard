#include <iostream>
#include "CourseDashboard.hpp"
#include "AuthenticationProvider.hpp"
#include "picosha2.h"
#include "User.hpp"

int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    
    AuthenticationProvider a;
    User user1("joanna", "bed", User::Group::evening, "teo", "fire", "email", a.hashPassword(""));
  
    std::cout << user1.getPassword() << std::endl;
    std::cout << std::boolalpha << a(user1, "email", a.hashPassword("")) << std::endl;
 
    cdb.saveToFile("userDatabase.txt");
    cdb.loadFromFile("userDatabase.txt");

    return 0;
}
