#pragma once
#include <string>
#include "curl/curl.h"
#include <memory>

class Server
{
public:
    Server();
    ~Server();
    void downloadUsers();
    bool checkIfFileExist();
    static size_t write_data(char*, size_t, size_t, void*);
private:
    static std::string data;
    CURL* curl;
    std::string serverName = "http://coursedashboard.pl/";
    std::string pathToFile = "userDatabase.json";
};
