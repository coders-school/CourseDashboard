#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include "FileHandler.hpp"


TEST(FileHandlerTests, readReturnsPreviouslyWrittenContent)
{
	std::string testFilePath = "iotest.txt";
	std::string dummyStr = "line one\nline two\nline|three\n";
	FileHandler sut(testFilePath);
	sut.write(dummyStr);
	auto read = sut.read();
	EXPECT_EQ(read, dummyStr);
}

TEST(FileHandlerTests, readingFromNotExistingFileThrows)
{
	FileHandler sut("notExistingFile.txt");
	ASSERT_THROW(sut.read(), std::invalid_argument);
}
