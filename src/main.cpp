  #include "train.hpp"
  #include "stud.hpp"
  #include <iostream>
  #include "CourseDashboard.hpp"


  int main()
  {
      std::cout << "Course Dashboard" << std::endl;
      StudentData database;
      database.addUser("Wiktor","Arakis14","github.com/test1","weekend group");
      database.addUser("Jan","kowal1234","github.com/test2","evening group");
      database.addUser("Test","something ","anything","test");
      std::cout<<"=============================="<<std::endl;
      database.viewUsers();
      database.deleteUser(1);
      std::cout<<"==="<<std::endl;
      database.viewUsers();


      return 0;
  } 

