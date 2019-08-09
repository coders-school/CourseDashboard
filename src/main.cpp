#include <iostream>
#include "CourseDashboard.hpp"
#include "User.hpp"

int main()
{
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon","SzymonGajewski","wieczorowa","SzymonGajewski","SzymonGajewski");
    addUser(u1);
    u1.getAllInfo();
    return 0;
}
