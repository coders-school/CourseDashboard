#include <iostream>
#include "CourseDashboard.hpp"
#include "Coders.hpp"
#include "ModifyCoders.hpp"

int main()
{
    std::cout << "Course Dashboard" << std::endl;
    ModifyCoders edit;
    Coders::Group wGroup;
    wGroup = Coders::Group::weekends;
    Coders::Group eGroup;
    eGroup = Coders::Group::evenings;
    Coders Vandam {"Łukasz", "vandam", "https://github.com/lucaswalicki", "fireVandam", wGroup};
    Coders Ziomeczek {"Sylwia", "TheDude", "gitDude", "fireDude", wGroup};
    Coders TestSubject {"Coder", "Enignma", "gitCoder", "fireCoder", eGroup};
    edit.addUser(Ziomeczek);
    edit.addUser(Vandam);
    edit.addUser(TestSubject);
    edit.printEveryone();
    edit.deleteUser(Vandam);
    edit.printEveryone();
    return 0;
}
