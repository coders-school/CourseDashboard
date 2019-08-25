#include <gtest/gtest.h>
#include <fstream>
#include <ios>
#include <iterator>
#include <string>
#include "UserIOHandler.hpp"

namespace
{
constexpr const char* testFilePath = "iotest.txt";
constexpr const char* notExistingFilePath = "/not/existing/aaa.txt";
constexpr const char* dummyStr = "dummy";

std::string actual(const std::string& filePath)
{
	std::fstream fileStream(filePath);
	std::string strBuff(
		(std::istreambuf_iterator<char>(fileStream)), 
		std::istreambuf_iterator<char>());
	fileStream.close();
	return strBuff;
}

}

TEST(UserIOHandlerTests, shouldWriteToFile)
{
	UserIOHandler sut;
	sut.write(testFilePath, dummyStr);
	EXPECT_EQ(actual(testFilePath), dummyStr);
}