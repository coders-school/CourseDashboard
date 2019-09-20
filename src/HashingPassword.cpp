#include "HashingPassword.hpp"
#include<iostream>

std::string HashingPassword::hashPassword(std::string p)
 {
     std::string hashedPassword_ = picosha2::hash256_hex_string(p);
     return hashedPassword_;
 }