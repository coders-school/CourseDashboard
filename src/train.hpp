#include <string>
#include <vector>
#include "stud.hpp"


class StudentData
 {
 private:
 std::vector<Student>studData;
 public:
     StudentData();
     void addUser(std::string name, std::string discordName, std::string gitLink, std::string group);
     void viewUsers();
     void deleteUser(int userNumber);
//     void editUser(int userNumber,std::string name, std::string surname, std::string discordName);

 };




