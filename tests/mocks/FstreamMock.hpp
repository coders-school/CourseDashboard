#pragma once

#include <gmock/gmock.h>
#include <string>

#include "IFstream.hpp"


class FstreamMock : public IFstream
{
public:
	MOCK_CONST_METHOD1(tryToWrite, void(const std::string& content));
	MOCK_CONST_METHOD0(tryToRead, std::string());
	MOCK_CONST_METHOD0(getFilePath, std::string());
};