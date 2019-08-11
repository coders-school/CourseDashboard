#include<CourseDashboard.hpp>
#include<User.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int main()
{
    CourseDashboard helper;
    std::vector<std::string> userLine0 = helper.readData("users_data.txt", 0);
    helper.printVs(userLine0);

    User user1("Joanna", "Bednarska", "Joanna", "teojdb");
    user1.printUserdata();
    user1.changeData("joanna", "bed", "Joanna", "teojdb");
    user1.printUserdata();
    user1.deleteUser();
    user1.printUserdata();

    User user2(userLine0);
    user2.printUserdata();   

    return 0;
}
