#pragma once

#include <gmock/gmock.h>
#include <string>

#include "IFstream.hpp"


class FstreamMock : public IFstream
{
public:
	MOCK_METHOD(void, tryToWrite, (const std::string& content), (override));
	MOCK_METHOD(std::string, tryToRead, (), (override));
	MOCK_METHOD(std::string, getFilePath, (), (const, override));
};