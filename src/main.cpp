#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
    User u1("Szymon", "SzymonGajewski","haslo","mail", "wieczorowa", "SzymonGajewski", "SzymonGajewski");
    User u2("Natalia", "NG", "wieczorowa","HASLO","mail2", "NG90", "Natalia");
    User uR("rr", "rr","XXXX","xxxx", "R", "R", "R");
    cdb.createUser(uR);   
    cdb.createUser(u1);
    cdb.createUser(u2);
    cdb.login();
    cdb.saveInFile();
    cdb.retriveUserByNick("SzymonGajewski");
    cdb.showAll();
    cdb.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<< std::endl;
    cdb.readFromFile();
    return 0;
}
