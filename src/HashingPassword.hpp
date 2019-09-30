#pragma once
#include "../external/picosha2.h"

class HashingPassword
{
    std::string hashedPassword_;
    
    public:

    HashingPassword() = default;
    std::string hashPassword(std::string p);

};