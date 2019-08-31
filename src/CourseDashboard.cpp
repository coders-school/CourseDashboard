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
    
void CourseDashboard::saveUsersToFile(std::string filename)
{
    std::ofstream file(filename, std::ofstream::out | std::ofstream::trunc);
    if (file.is_open())
    {
        for (auto & user : users_)
        {
            file    << user.getName() << ';'
                    << user.getNick() << ';'
                    << user.getPassword() << ';'
                    << user.getMail() << ';'
                    << user.getGroup() << ';'
                    << user.getGitHub() << ';'
                    << user.getFirecode() << ';'
                    << '\n';
        }
    }
}

void CourseDashboard::loadUsersFromFile(std::string filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::vector<std::string> vstrUser{};
        std::string tmpLine, tmpValue;
        users_.clear();
        while(std::getline(file, tmpLine))
        {  
            std::stringstream sstream(tmpLine);
            while (std::getline(sstream, tmpValue,';'))
            {
                vstrUser.push_back(tmpValue);
            }
            User loopUser(
                vstrUser[0], vstrUser[1], vstrUser[2], vstrUser[3], vstrUser[4], vstrUser[5], vstrUser[6]);
            users_.emplace_back(loopUser);
            vstrUser.clear();
        }
    }
}
