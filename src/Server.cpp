#include "Server.hpp"
#include "nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <fstream>

void Server::downloadUsers()
{
/*
    CURL* curl = curl_easy_init();
    std::string readBuf{};
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://coursedashboard.pl/userDatabase.txt");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, readBuf);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuf << "\n";
    }
*/
/*
    std::string text{};
    std::cout << "path to file: " << this->pathToFile << "\n";   
 
    try
    {
        std::ifstream file("userDatabase.txt");
        while (file.is_open())
        {
            std::cout << "i'm here. \n";
            getline(file, text);
            if (file.eof())
            {
                file.close();
                std::cout << "File is closed. \n";
            }
        }
        std::cout << "text: " << text << "\n";

    }   
    catch(std::ios_base::failure& e)
    {
        std::cerr << "Read from file: " << this->pathToFile << "\n"
                  << "Error message: " << e.what() << "\n";
    }
*/
}

bool Server::checkConnection()
{
    return system("ping www.coursedashboard.pl");
}

bool Server::checkIfFileExist()
{
    std::ifstream file(pathToFile);
    return file.is_open();
}
