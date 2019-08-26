#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User ng("ngName", "ngNick", "ngPassword", "ngMail", "ngGroup", "ngGithub", "ngFirecode");
    User rh("rhName", "rhNick", "rhPassword", "rhMail", "rhGroup", "rhGithub", "rhFirecode");
    User ph("phName", "phNick", "phPassword", "phMail", "phGroup", "phGithub", "phFirecode");
    cdb.createUser(ng);
    cdb.createUser(rh);
    cdb.createUser(ph);
    cdb.showAll();
    return 0;
}
