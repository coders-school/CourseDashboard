#include <gtest/gtest.h>
#include "Utility.hpp"

struct UtilityTests : ::testing::Test
{
	User szymon{"Szymon", "SzymonG", "wieczorowa", "SzymonG", "SzymonG"};
	User kamil{"Kamil", "Kamil.W", "wieczorowa1", "Kamil.W", "Kamil.W"};

	Users users = {szymon, kamil};
};

TEST_F(UtilityTests, canConvertVectorOfUsersToJson)
{
	auto result = convertToJson(users).dump();

	ASSERT_NE(result.find(szymon.getNick()), std::string::npos);
	ASSERT_NE(result.find(kamil.getNick()), std::string::npos);
}

TEST_F(UtilityTests, canConvertFromJsonToVector)
{
	auto result = convertToJson(users).dump();
	users.clear();

	users = convertToArray(result);

	ASSERT_TRUE(users.size() == 2);
	ASSERT_EQ(users[0].getNick(), szymon.getNick());
	ASSERT_EQ(users[1].getNick(), kamil.getNick());

}

TEST_F(UtilityTests, canReciveExceptionWhenStringIsNotJsonString)
{
	ASSERT_THROW(convertToArray("NotJsonString"), json::parse_error);
}
