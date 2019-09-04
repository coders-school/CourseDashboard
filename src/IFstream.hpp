#pragma once

#include <memory>
#include <string>

class IFstream
{
public:
	virtual ~IFstream() = default;
	virtual void tryToWrite(const std::string& content) const = 0;
	virtual std::string tryToRead() const = 0;
	virtual std::string getFilePath() const = 0;
};

using IFstreamPtr = std::unique_ptr<IFstream>;
