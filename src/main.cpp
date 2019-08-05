#include <iostream>
#include "UserData.hpp"
#include <unistd.h>
#include "Group.hpp"

int main()
{
    std::system("clear");
    UserData user("Krzysiek", "Cypher", "https://www.testowy-link.og", "https://www.testowy-link-22.og", Group::weekend);
    
    int choice = 0;
    do
    {
    std::system("clear");
    std::cout << "Dashboard: " << std::endl;
    std::cout << "1. See info about students" << std::endl;
    std::cout << "2. Add little changes" << std::endl;
    std::cout << "3. Quit program" << std::endl;
    std::cin >> choice;
    std::system("clear"); 
    
    
       switch(choice)
         {
             case 1:
                     {
                        std::cout << user << std::endl;
                        std::cout << "[Press enter to go back]" << std::endl; 
                        std::cin.ignore();
                        std::cin.get();
                        break;
                     }
             case 2: 
                     {
                        std::cin >> user;
                        std::system("clear");
                        break;
                     }
             case 3: 
                     {

                        return 0;
                
                     }
        
            default: break;
            
        }
    
    } while(choice!=3);
    
    return 0;
}
