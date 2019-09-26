#include "Server.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "curl/curl.h"
#include "Utility.hpp"
#include "User.hpp"

std::string data;

Server::Server()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

Server::~Server()
{
    curl_global_cleanup();
}

size_t Server::write_data(char* buf, size_t size, size_t nmemb, void* up)
{
    for (size_t c = 0; c < size*nmemb; c++)
        data.push_back(buf[c]);
    return size * nmemb;
}

void Server::downloadUsers()
{
    curl = curl_easy_init();

    if (curl)
    {
        std::string path = serverName + pathToFile;
        curl_easy_setopt(curl, CURLOPT_URL, path.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_data);
        curl_easy_perform(curl);

        if (checkIfFileExist())
        {
            Users listOfUsers = convertToArray(data);
            std::cout << "\nUsers has been uploaded into database ;) \n\n";
            for (auto user : listOfUsers)
                std::cout << user.getNick() << "\n";
        }
  
        curl_easy_cleanup(curl);
    }
    else
        std::cout << "Initialization has been failed. \n";
}

bool Server::checkIfFileExist()
{
    return (data[0] != '<');
}

