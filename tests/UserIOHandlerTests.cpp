#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fstream>
#include <ios>
#include <iterator>
#include <string>
#include "IFstream.hpp"
#include "Fstream.hpp"
#include "UserIOHandler.hpp"
#include "mocks/FstreamMock.hpp"

using namespace testing;

namespace
{
constexpr const char* testFilePath = "iotest.txt";
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
	//todo: replace with mock by delegating action to real object
	UserIOHandler sut(new Fstream(std::string(testFilePath)));
	sut.write(dummyStr);
	EXPECT_EQ(actual(testFilePath), dummyStr);
}

TEST(UserIOHandlerTests, onWriteShouldOnceCallTryToWriteOnFstream)
{
	FstreamMock* fsMock = new FstreamMock;

	EXPECT_CALL(*fsMock, tryToWrite(_))
		.Times(1);

	UserIOHandler sut(fsMock);
	sut.write(dummyStr);
}

TEST(UserIOHandlerTests, onWriteShouldPrintToCerrOnFailure)
{
	FstreamMock* fsMock = new FstreamMock;

	ON_CALL(*fsMock, tryToWrite(_))
		.WillByDefault(Throw(std::ios_base::failure(dummyStr)));

	EXPECT_CALL(*fsMock, tryToWrite(_))
		.Times(1);

	EXPECT_CALL(*fsMock, getFilePath())
		.Times(1);

	UserIOHandler sut(fsMock);

	testing::internal::CaptureStderr();
	sut.write(dummyStr);
	std::string stdErr = testing::internal::GetCapturedStderr();
	EXPECT_NE(stdErr.find(dummyStr), std::string::npos);
}

TEST(UserIOHandlerTests, shouldReadFromFile)
{
	UserIOHandler sut;
	sut.write(testFilePath, dummyStr);

	std::string str;
	sut.read(testFilePath, str);
	EXPECT_EQ(str, dummyStr);
}
