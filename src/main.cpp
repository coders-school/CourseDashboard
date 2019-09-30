#include <iostream>
#include "picosha2.h"
#include "CourseDashboard.hpp"
#include "User.hpp"
#include "AuthenticationProvider.hpp"


bool provideCredentials(const CourseDashboard & dashboard)
{
    std::cout << "Email: ";
    std::string email{};
    std::cin >> email;
    std::cout << "Password: ";
    std::string password{};
    std::cin >> password;
    return dashboard.login(email, password);
}

int main()
{
    CourseDashboard dashboard;
    std::cout << "Course Dashboard" << std::endl;
    std::cout << "Please log in to continue\n";
    while (not provideCredentials(dashboard))
        std::cout << "Incorrect login, try again\n";
  
    dashboard.addUser();
    dashboard.saveToJson("userDatabase.txt");

    User user1("joanna", "bed", User::Group::evening, "teo", "fire", "email", "12345");
    std::cout << user1.getPassword() << std::endl;
    AuthenticationProvider a;
    std::cout << std::boolalpha << a(user1, "email", "5994471abb01112afcc18159f6cc74b4f511b99806da59b3caf5a9c173cacfc5") << std::endl;

    return 0;
}
