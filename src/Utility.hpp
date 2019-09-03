#include <string>
#include "nlohmann/json.hpp"
#include "User.hpp"

using namespace nlohmann;

inline json convertToJson(const Users& users)
{
    auto jsonArray = json::array();

    for(const auto & user : users) {
        jsonArray.push_back(user.toJson());
    }

    return jsonArray;
}

inline Users convertToArray(const std::string& jsonString)
{
    auto jsonArray = json::parse(jsonString);

    Users array;
    for(auto& jsonE : jsonArray) {
        array.push_back(User(jsonE));
    }

    return array;
}
