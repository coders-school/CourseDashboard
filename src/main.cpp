#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    cdb.showAll();
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonG", User::Group::evening, "SzymonG", "SzymonG");
    cdb.createUser(u1);
    cdb.saveToFile("userDatabase.txt");
    cdb.clearUserDatabase();
    cdb.loadFromFile("userDatabase.txt");
    cdb.showAll();
    auto szymon = cdb.retriveUserByNick("SzymonG");

    cdb.updateUser(szymon, User::Group::weekend, "S");
    std::cout<<"after update: "<<std::endl;
    cdb.showAll();

    cdb.deleteUserByNick("SzymonG");
    std::cout<<"after delete: "<<std::endl;
    cdb.showAll();
    return 0;
}
