#include <iostream>
#include <tuple>
#include "CourseDashboard.hpp"

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

    return 0;
}
