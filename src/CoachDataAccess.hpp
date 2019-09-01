#pragma once
#include <string>
#include <vector>
#include "Coach.hpp"
#include "Connect.hpp"

class CoachDataAccess
{
public:
    CoachDataAccess(Connect & connect);
    bool createCoach(const Coach & coach);
    bool logIn(const std::string email, const std::string password);

protected:
    std::vector<Coach> coaches_;
private:
    Connect & connect_;
};