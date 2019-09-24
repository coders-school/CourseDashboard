#pragma once
#include <string>

class Server
{
public:
    Server() = default;
    void downloadUsers();
    bool checkIfFileExist();

private:
    std::string serverName = "http://coursedashboard.pl/";
    std::string pathToFile = "userDatabase.json";
};
