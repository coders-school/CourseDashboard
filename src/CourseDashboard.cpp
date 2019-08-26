#include "CourseDashboard.hpp"

CourseDashboard::CourseDashboard() {}

void CourseDashboard::showAll()
{
    for (auto & user : users_)
    {
        std::cout << user.getAllInfo();
    }
}

void CourseDashboard::createUser(const User & user)
{
    users_.emplace_back(user);
}

void CourseDashboard::deleteUserByNick(std::string nick)
{  
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });

    if (it != std::end(users_))
    {
        users_.erase(it);
    }
}

void CourseDashboard::retriveUserByNick(std::string nick)
{
    auto it = std::find_if(std::begin(users_), std::end(users_), [nick](const auto & user)
    {
        return user.getNick() == nick;
    });
    
    if (it != std::end(users_))
    {
        std::cout << it->getAllInfo();
    }
}

void CourseDashboard::updateUser(User & user)
{
    unsigned int number;
    std::cout << user.getAllInfo();
    std::cout << "Which data You want to edit? Give number: " << '\n';
    std::cin >> number;
    std::string name, nick, group, gitHub, firecode;
    switch (number) {
    case 1:
        std::cout << "Give new value to data: ";
        std::cin >> name;
        user.setName(name);
        break;
    case 2:
        std::cout << "Give new value to data: ";
        std::cin >> nick;
        user.setNick(nick);
        break;
    case 3:
        std::cout << "Give new value to data: ";
        std::cin >> group;
        user.setGroup(group);
        break;
    case 4:
        std::cout << "Give new value to data: ";
        std::cin >> gitHub;
        user.setGitHub(gitHub);
        break;
    case 5:
        std::cout << "Give new value to data: ";
        std::cin >> firecode;
        user.setFirecode(firecode);
        break;
    default:
        std::cout << "You gave wrong value.";
        break;
    }
}

void CourseDashboard::login()
{
    std::system("clear");
    bool loginTest{};
    do
    {
        std::string userEmail, userPassword;
        std::cout << "Enter Your e-mail address: ";
        std::cin >> userEmail;
        std::cout << "Enter Your password: ";
        std::cin >> userPassword;
        std::system("clear");
        auto setLoginTestBoolTrueIfLoginIsCorrect = 
            [&userEmail, &userPassword, &loginTest](const User & users_)
            {
                if ( users_.getMail() == userEmail && users_.getPassword() == userPassword )
                    return loginTest = true;
                return false; 
            };
        auto it = std::find_if(users_.begin(), users_.end(), setLoginTestBoolTrueIfLoginIsCorrect);       
        if (loginTest == true)
        {
            std::cout << "You have succesfuly logged in " << it->getName() << "!\n";
            std::cout << "Printing Your user info:\n" << it->getAllInfo();
        }
        else
        {
            std::cout << "Login or Password is incorect! Please try again!" << '\n';
        }
    } while (loginTest != true);            
}