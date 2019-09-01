#include "CoachDataAccess.hpp"
#include <string>
#include <vector>
#include <algorithm>

CoachDataAccess::CoachDataAccess(Connect & connect) : connect_(connect) {}

bool CoachDataAccess::createCoach(const Coach & coach)
{
    coaches_.emplace_back(coach);
    return connect_.login(coach.getEmail(), coach.getPassword());
}

bool CoachDataAccess::logIn(const std::string email, const std::string password)
{
    auto it = std::find_if(std::begin(coaches_), std::end(coaches_), [email] (const auto & coach){ return coach.getEmail() == email; });
    if (it != std::end(coaches_) && it->getEmail() == email && it->getPassword() == password)
    {
        if(connect_.checkIfUserIsAlreadyLoggedIn() == true)
        {
            std::cout << "Already logged in" << std::endl;
            return false;
        }
        else
        {
            connect_.login(email, password);
            return true;
        }
    }
    else   
    {
        std::cout << "Wrong email or password. Try again." << std::endl;
        return false;
    }
}

