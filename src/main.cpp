#include <iostream>
#include "UserData.hpp"
#include "Group.hpp"
#include "UserDataAccessLayer.hpp"
#include "CommonUtilities.hpp"

namespace
{

void printMenu()
{
	std::cout << "##Course Dashboard##\n"
			  << "#1. [Q|q]uit\n"
			  /*<< "[I|i]nfo\n"*/
			  << "#2. [P|p]rint users data\n"
			  << "#3. [C|c]reate user data\n"
			  << "#4. [R|r]ead user data\n"
			  << "#5. [U|u]pdate user data\n"
			  << "#6. [D|d]elete user data\n";
}

std::string enterNickname()
{
	std::cout << "Enter user's nickname: ";
	std::string nickname;
	std::cin >> nickname;
	return nickname;
}

void executeOption(const char option, UserDataAccessLayer& usrDal)
{
	switch(option)
	{
		case 'P':
		case 'p':
		{
			usrDal.printUserData();
			break;
		}
		case 'C':
		case 'c':
		{
			usrDal.createUser();
			break;
		}
		case 'R':
		case 'r':
		{
			auto usr = usrDal.readUser(enterNickname());
			if(usr)
				std::cout << usr.value() << "\n";
			break;
		}
		case 'U':
		case 'u':
		{
			usrDal.updateUser(enterNickname());
			break;
		}
		case 'D':
		case 'd':
		{
			usrDal.deleteUser(enterNickname());
			break;
		}
		default:
			break;
	}
}

}

int main()
{
	std::system("clear");
	char option = '0';
	UserDataAccessLayer usrDal;
	do
	{
		postponedConsoleClear(std::chrono::seconds(1));
		printMenu();
		std::cout << "> ";
		std::cin >> option;
		executeOption(option, usrDal);
	} while(option!='q' && option!='Q');
	postponedConsoleClear(std::chrono::seconds(1));
	return 0;
}
