#include <gtest/gtest.h>
#include "Utility.hpp"

TEST(UtilTests, canConvertVectorOfUsersToJson)
{
	std::vector<User> users = {
		User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski"),
		User("Kamil", "Kamil.Wszkiewicz", "wieczorowa1", "Kamil.Wszkiewicz", "Kamil.Wszkiewicz"),
	};

	auto result = convertToJson(users).dump();

	ASSERT_TRUE(result.find("Szymon") != std::string::npos);
	ASSERT_TRUE(result.find("Kamil.Wszkiewicz") != std::string::npos);
}

TEST(UtilTests, canConvertFromJsonToVector)
{
	std::vector<User> users = {
		User("Szymon", "SzymonGajewski", "wieczorowa", "SzymonGajewski", "SzymonGajewski"),
		User("Kamil", "Kamil.Wszkiewicz", "wieczorowa1", "Kamil.Wszkiewicz", "Kamil.Wszkiewicz"),
	};

	auto result = convertToJson(users).dump();
	users.clear();

	users = convertToArray(result);

	ASSERT_TRUE(users.size() == 2);
	ASSERT_TRUE(!users[0].getName().compare("Szymon") || !users[0].getName().compare("Kamil"));

}

TEST(UtilTests, canReciveExceptionWhenStringIsNotJsonString)
{
	ASSERT_THROW(convertToArray("NotJsonString"), std::invalid_argument);
}