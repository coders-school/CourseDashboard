#pragma once
#include <string>
#include <iostream>

enum class Group
{
    weekend = 0,
    evening = 1
};

inline std::string toString(Group group)
{
    switch(group)
    {
        case Group::weekend:
            return "weekend";
        case Group::evening:
            return "evening";
        default:
            return "No group";
    }
}

inline std::ostream &operator << (std::ostream &out, Group group)
{
    return out << toString(group);
}


