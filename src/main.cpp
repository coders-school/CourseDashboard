  #include "CourseDashboard.hpp"
  #include "studbase.hpp"
  #include "stud.hpp"
  #include <iostream>
  #include <fstream>
  #include <iterator>


  int main()
  {
//      std::ofstream out_file { "../dataBase.txt",std::ios::app };
//      if (!out_file)
//      {
//          std::cerr << "Error" << std::endl;
//          return 1;
//      }
      std::cout << "Course Dashboard" << std::endl;
      StudentData database;
      Student wiktor {"Wiktor","Arakis14","github.com/test1","weekend group","firecodelink#1"};
      database.addUser(wiktor);
//      out_file << wiktor<<std::endl;
      database.viewUsers();
      database.deleteUser("Wiktor");
      database.addUser(wiktor);
      std::cout << wiktor << std::endl;

      return 0;
  } 

