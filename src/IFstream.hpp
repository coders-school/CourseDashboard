#pragma once

#include <ios>
#include <memory>
#include <string>

class IFstream
{
public:
	IFstream(const std::string& filePath)
	: filePath_(filePath)
	{
	}

	virtual ~IFstream() = default;
	virtual void tryToWrite(const std::string& content) = 0;
	virtual std::string tryToRead() = 0;
	virtual std::string getFilePath() const { return filePath_; }

protected:
	IFstream() = default;
	std::string filePath_;
};

using IFstreamPtr = std::unique_ptr<IFstream>;