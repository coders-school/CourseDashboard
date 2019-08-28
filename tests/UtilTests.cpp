#include <gtest/gtest.h>
#include "Utilits.hpp"

TEST(UtilTests, canConvertVectorOfUsersToJsonString)
{
	std::vector<User> users = {
		User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski"),
		User("Kamil", "Kamil.Wszkiewicz", "wieczorowa1", "Kamil.Wszkiewicz", "Kamil.Wszkiewicz"),
	};

	auto result = convertToJson(users);

	ASSERT_TRUE(result.find("Szymon") != std::string::npos);
	ASSERT_TRUE(result.find("Kamil.Wszkiewicz") != std::string::npos);
}

TEST(UtilTests, canConvertFromJsonToVector)
{
	std::vector<User> users = {
		User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski"),
		User("Kamil", "Kamil.Wszkiewicz", "wieczorowa1", "Kamil.Wszkiewicz", "Kamil.Wszkiewicz"),
	};

	auto result = convertToJson(users);
	users.clear();

	users = convertToArray(result);

	ASSERT_TRUE(users.size() == 2);
	ASSERT_TRUE(!users[0].getName().compare("Szymon") || !users[0].getName().compare("Kamil"));

}