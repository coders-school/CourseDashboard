#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User ph("ph1", "ph2", "ph3", "ph4", "ph5", "ph6", "ph7");
    cdb.createUser(ph);
    cdb.showAll();
    return 0;
}
