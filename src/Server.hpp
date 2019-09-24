#pragma once
#include <string>

class Server
{
public:
    Server() = default;
    bool checkConnection();
    void downloadUsers();
    bool checkIfFileExist();

private:
    std::string serverName = "http://coursedashboard.pl";
    std::string ip = "46.242.244.62";
    size_t port = 80;
    std::string pathToFile = "userDatabase.txt";
};
