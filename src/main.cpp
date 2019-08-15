#include <iostream>
#include "CourseDashboard.hpp"
#include "Student.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <cstdlib>


using namespace std;

int main()
{
    for(;;){
    system("clear");
    char choice;
    std::cout << "Course Dashboard" << std::endl;
    std::cout << "1. Wstawianie uzytkownika." << std::endl;
    std::cout << "2. Ponowne wprowadzenie danych dla studenta po Nicku" << std::endl;
    std::cout << "3. Usuwanie uzytkownika po Nicku" << std::endl;
    std::cout << "4. Wyswietl dane studenta po Nicku." << std::endl;
    std::cout << "5. Wyjscie z programu." << std::endl;
    std::cin >> choice;

    CourseDashboard basicUser;

    switch(choice){    
        case '1':
            {
                std::string nick, name, gitHub, firecode;
                std::cout<<"Podaj nick: ";
                std::cin>>nick;
                std::cout<<"Podaj imie: ";
                std::cin>>name;
                std::cout<<"Podaj nick na GitHub: ";
                std::cin>>gitHub;
                std::cout<<"Podaj nick na Firecode: ";
                std::cin>>firecode;

                Student student(nick, name, gitHub, firecode);
                basicUser.addStudent(student);
            }
        break;
        case '2':
            {
                std::string nick;
                std::cout<<"Podaj nick dla którego chcesz prowadzic nowe dane: ";
                std::cin>>nick;
                basicUser.changeStudentData(nick);

            }
        break;
        case '3':
            {
                std::string nick;
                std::cout<<"Podaj nick studenta, ktorego chcesz usunac z bazy: ";
                std::cin>>nick;
                basicUser.removeStudent(nick);
            }
        break;
        case '4':
            {
                std::string nick;
                std::cout<<"Podaj nick studenta, ktorego dane chesz wysietlic: ";
                std::cin>>nick;
                basicUser.showStudentData(nick);
            }
        break;
        case '5':
            {
                exit(0);
            }
        break;
        default: std::cout<<"Wybierz cyfre z zakresu 1-4"<<std::endl;
        }
    }
    return 0;
}
