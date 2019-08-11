#include <iostream>
#include "UserData.hpp"
#include <unistd.h>
#include "Group.hpp"
#include "UserDataAccessLayer.hpp"


int main()
{
	char option = '0';
	UserDataAccessLayer usrDal;
	do
	{
		std::cout << "Course Dashboard: " << "\n"
				  << "[Q|q]uit\n"
				  /*<< "[I|i]nfo\n"*/
				  << "[C|c]reate user data\n"
				  << "[R|r]ead user data\n"
				  << "[U|u]pdate user data\n"
				  << "[D|d]elete user data\n";

		std::cout << "> ";
		std::cin >> option;

		switch(option)
		{
			case 'C':
			case 'c':
			{
				usrDal.createUser();
				break;				
			}
			case 'R':
			case 'r':
			{
				std::cout << "Enter user's nickname: ";
				std::string nickname;
				std::cin >> nickname;
				auto usr = usrDal.readUser(nickname);
				if(usr)
					std::cout << usr.value() << "\n";
				break;
			}
			case 'U':
			case 'u':
			{
				std::cout << "Enter user's nickname: ";
				std::string nickname;
				std::cin >> nickname;
				usrDal.updateUser(nickname);
				break;
			}
			case 'D':
			case 'd':
			{
				std::cout << "Enter user's nickname: ";
				std::string nickname;
				std::cin >> nickname;
				usrDal.deleteUser(nickname);
				break;
			}
			default:
				break;
		}
	} while(option!='q' && option!='Q');


	return 0;
}
