#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon","SzymonGajewski","wieczorowa","SzymonGajewski","SzymonGajewski");
    cdb.createUser(u1);
    u1.getAllInfo();
    return 0;
}
