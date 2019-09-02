#include <iostream>
#include "CourseDashboard.hpp"


int main()
{
    CourseDashboard cdb;
    std::cout << "Course Dashboard" << std::endl;

    User u1("Jan",
            "JanKowalski",
            "weekendowa",
            "jkowalski",
            "jkowalski");

    std::cout << cdb.showAll();

    cdb.createUser(u1);

    std::cout << cdb.showAll();

    cdb.retriveUserByNick("PiotrNowak");  // TODO improve function
    cdb.loadFromFile("baza danych.txt");
    User u2("Jan Kowalski", "Jan123", "weekendowa", "JanK", "JanK");
    cdb.createUser(u2);
    std::cout << cdb.showAll();
    cdb.saveToFile("baza danych.txt");
    return 0;
}
