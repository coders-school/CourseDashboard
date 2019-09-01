#include <iostream>
#include "CourseDashboard.hpp"
#include "Connect.hpp"
#include "Coach.hpp"
#include "UserData.hpp"
#include "CoachDataAccess.hpp"
#include <cctype>

int main()
{
    Connect connect;
    Coach Lukasz("testEmail", "testPassword");
    Coach Igor("randEmail", "randPassword");

    CoachDataAccess coachDA(connect);
    coachDA.createCoach(Lukasz);
    coachDA.createCoach(Igor);

    coachDA.logIn("testEmail", "testPassword");
    coachDA.logIn("nomail", "nopassword");
    coachDA.logIn("randEmail", "randPassword");
    

    

    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;
     User u1("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski", "szymomn@gmail.com", "12345678");
     User u2("Aslan", "Maschadov", "DPW", "aslan007", "amasch", "aslan@maschadov@gmail.com", "testaslan");
     User u3("Daniel", "LinQ", "wieczorowa/weekendowa", "linq007", "linq007", "djtarnawski@gmail.com", "idontremember");
    UserData usd(connect);
     usd.createUser(u1);
     usd.createUser(u2);
    usd.createUser(u3);
    usd.showAll();
    cdb.readingFromFile();
    cdb.savingToFile(u1);
    cdb.savingToFile(u2);
    usd.logIn("szymomn@gmail.com", "12345678");
    usd.logIn("dJtArNawSkI@gmail.com", "idontremember");
    usd.logIn("dJtArNawSkI@gmail.com", "testaslan");

    usd.deleteUserByNick("SzymonGajewski");
    std::cout<<"after delete: "<<std::endl;
    usd.showAll();
    return 0;
}
