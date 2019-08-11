#pragma once

#include <string>
#include <stdexcept>

struct NoSuchUserException : public std::invalid_argument
{
    NoSuchUserException(std::string message) 
        : invalid_argument(message)  {};

    NoSuchUserException(const char* message)
        : invalid_argument(message) {};
};

struct UniqueEntryException : public std::runtime_error
{
    UniqueEntryException(std::string message) 
        : std::runtime_error(message) {};

    UniqueEntryException(const char* message) 
        : std::runtime_error(message) {};
};