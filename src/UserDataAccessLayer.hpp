#pragma once
#include "UserData.hpp"
#include <map>
#include <optional>

class UserDataAccessLayer
{
public:
	UserDataAccessLayer() = default;
	~UserDataAccessLayer() = default;

	void createUser();
	std::optional<UserData> readUser(const std::string& nick) const;
	void updateUser(const std::string& nick);
	void deleteUser(const std::string& nick);

private:
	std::map<std::string, UserData> userNickToData;
};