#include "UserData.hpp"
#include "UserDataAccessLayer.hpp"
#include <memory>
#include <string>
#include <cstdlib>
#include "Group.hpp"
#include <utility>

namespace
{

std::optional<Group> inputToGroup(int input)
{
	switch(input)
	{
		case 1:
			return std::optional<Group>{Group::weekend};
		case 2:
			return std::optional<Group>{Group::evening};
		default:
			std::cout << "Incorrect group";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::system("clear");
			return std::nullopt;
	}
}

}

void UserDataAccessLayer::createUser()
{
	std::cout << "enter unique nickname: ";
	std::string nickname;
	std::cin >> nickname;
	if(userNickToData.find(nickname) != userNickToData.end())
	{
		std::cout << "\n nickname already exists in db! \n";
		return; //todo implement going back to entering data
	}

	std::cout << "\n enter first name: ";
	std::string name;
	std::cin >> name;

	std::cout << "\n enter firecode link: ";
	std::string fcLink;
	std::cin >> fcLink;

	std::cout << "\n enter github link: ";
	std::string ghLink;
	std::cin >> ghLink;

	std::cout << "\n enter group (1 - weekend, 2 - evening): ";
	int groupChoice = 0;
	std::cin >> groupChoice;
	auto group = inputToGroup(groupChoice);
	if(!group)
	{
		//todo handle incorrect group
		return;
	}

	std::system("clear");
	userNickToData.try_emplace(nickname, name, nickname, fcLink, ghLink, *group);
}

std::optional<UserData> UserDataAccessLayer::readUser(const std::string& nick) const
{
	auto found = userNickToData.find(nick);

	if(found == userNickToData.end())
	{
		std::cout << "\n no username for given nickname in db! \n";
		return std::nullopt;
	}
	return std::optional<UserData>{found->second};
}

void UserDataAccessLayer::updateUser(const std::string& nick)
{
	auto found = userNickToData.find(nick);
	if(found != userNickToData.end())
	{
		auto& user = found->second;
		std::cin >> user;

		if(nick != user.getNick())
		{
			auto nodeHandler = userNickToData.extract(nick);
			nodeHandler.key() = user.getNick();
			userNickToData.insert(std::move(nodeHandler));
			return;
		}
	}

	std::cout << "No user with nick: " << nick << "\n";
}

void UserDataAccessLayer::deleteUser(const std::string& nick)
{
	if(userNickToData.erase(nick) == 0)
	{
		std::cout << "No user with nick: " << nick << "\n";
	}
	else
	{
		std::cout << "User with nick: " << nick << " has been removed \n";
	}
}