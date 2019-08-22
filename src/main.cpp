
#include <iostream>

#include "CourseDashboard.hpp"
#include "User.hpp"
#include "UserContainer.hpp"


int main()
{
    UserContainer uc;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    uc.createUser(u1);
    uc.retriveUserByNick("SzymonGajewski");
    uc.showAll();
    uc.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    uc.showAll();
    return 0;
}
