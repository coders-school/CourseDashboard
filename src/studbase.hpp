#include <string>
#include <vector>
#include "stud.hpp"


class StudentData
 {
    friend std::ostream &operator << (std::ostream &out, const StudentData &c);
 private:
    std::vector<Student> studData;
 public:
     void addUser(const Student &student);
     void viewUsers();
     void deleteUser(std::string name);
//     void editUser(int userNumber,std::string name, std::string surname, std::string discordName);

 };




