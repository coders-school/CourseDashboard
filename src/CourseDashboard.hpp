#pragma once
#include <vector>
#include "Student.hpp"


class CourseDashboard {
public:
    CourseDashboard();
    void addStudent(Student &);
    void removeStudent(std::string);
    void changeStudentData(std::string);
    void showStudentData(std::string);
private:
    std::vector<Student> student;
};
