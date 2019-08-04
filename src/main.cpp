#include <iostream>
#include "UserData.hpp"
#include <unistd.h>
int main()
{

    std::cout << "Menu: " << std::endl;
    std::cout << "1. Dodaj uczestnika" << std::endl;
    int wyborOpcji;
    std::cin >> wyborOpcji;
    
               UserData user;
    switch(wyborOpcji)
    {
        case 1: 
               user.setName("Krzysiek");
               user.setNick("Cypher");
               user.setFirecodeLink("https://www.testowy-link.og");
               user.setGithubLink("https://www.kolejny-test.og");
                
    }

    sleep(1);
    std::cout << "Obecni uczestnicy kursu: " << std::endl;
    std::cout << "Imie: " << user.getName() << std::endl;
    std::cout << "Nick: " << user.getNick() << std::endl;
    std::cout << "FirecodeLink: " << user.getFirecodeLink() << std::endl;
    std::cout << "GithubLink: " << user.getGithubLink() << std::endl;

    return 0;
}
