#include <iostream>
#include "UserData.hpp"
#include <unistd.h>
#include "Group.hpp"
int main()
{

     UserData user("Krzysiek", "Cypher", "https://www.testowy-link.og", "https://www.testowy-link-22.og");
    

    sleep(1);
    std::cout << "List of students: " << std::endl;
    std::cout << "Name: " << user.getName() << std::endl;
    std::cout << "Nick: " << user.getNick() << std::endl;
    std::cout << "FirecodeLink: " << user.getFirecodeLink() << std::endl;
    std::cout << "GithubLink: " << user.getGithubLink() << std::endl;
    return 0;
}
