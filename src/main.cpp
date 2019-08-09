#include <Trainer.hpp>
#include <Student.hpp>
#include <iostream>
#include "CourseDashboard.hpp"

int main()
{
    std::cout << "Course Dashboard" << std::endl;
     Trainer trainer1;
     trainer1.addUser("Wiktor","Lasota","Arakis14");
     trainer1.addUser("Jan","Kowalski","kowal1234");
     trainer1.addUser("Test","something ","anything");
     std::cout<<"=============================="<<std::endl;
     trainer1.viewUsers();
     trainer1.deleteUser(0);
     trainer1.deleteUser(1);

     return 0;
 }
