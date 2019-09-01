#include <string>

#include "../external/nlohmann/json.hpp"
#include "User.hpp"


inline nlohmann::json convertToJson( const std::vector<User>& users )
{
    nlohmann::json jsonArray = nlohmann::json::array();

    for(auto user : users) {
        jsonArray.push_back(user.toJson());
    }

    return jsonArray;
}

inline std::vector<User> convertToArray(const std::string& jsonString)
{
    try
    {
        nlohmann::json jsonArray = nlohmann::json::parse(jsonString);

        std::vector<User> array;
        for(auto& jsonE : jsonArray) {
            array.push_back(User(jsonE));
        }

        return array;
    }
    catch(const nlohmann::json::parse_error& e)
    {
        throw std::invalid_argument(e.what());
    }
}
