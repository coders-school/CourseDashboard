#include <vector>

#include "User.hpp"

class UserContainer
{
private:
    std::vector<User> users_;

public:
    UserContainer() = default;

    ~UserContainer() = default;

    void showAll();

    void createUser(const User & user);

    void deleteUserByNick(std::string nick);

    void retriveUserByNick(std::string nick);
    
    void updateUser(User & user);

};
