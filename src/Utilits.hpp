#include <string>

#include "../external/nlohmann/json.hpp"
#include "User.hpp"


inline std::string convertToJson( const std::vector<User>& users )
{
    nlohmann::json jsonArray = nlohmann::json::array();

    for(auto user : users) {
        jsonArray.push_back(user.toJson());
    }

    return jsonArray.dump();
}

inline std::vector<User> convertToArray(const std::string& jsonString)
{
    nlohmann::json jsonArray = nlohmann::json::parse(jsonString);

    std::vector<User> array;
    for(auto& jsonE : jsonArray) {
        array.push_back(User(jsonE));
    }

    return array;
}
