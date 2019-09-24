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

size_t write_data(char* buf, size_t size, size_t nmemb, void* up)
{
    for (size_t c = 0; c < size*nmemb; c++)
        data.push_back(buf[c]);
    return size * nmemb;
}

void Server::downloadUsers()
{
    CURL* curl;
    curl_global_init(CURL_GLOBAL_ALL);
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
        curl_global_cleanup();
    }
    else
        std::cout << "Somethng goes wrong. \n";
}

bool Server::checkIfFileExist()
{
    if (data[0] != '<')
        return true;
    else
    {
        std::cout << "File not exist \n";
        return false;
    }
}
