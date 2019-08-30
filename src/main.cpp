#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    UserData usd;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski","testEmail", "testPassword");
    usd.createUser(u1);
    usd.retriveUserByNick("SzymonGajewski");
    usd.showAll();
    usd.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    usd.showAll();
    return 0;
}
