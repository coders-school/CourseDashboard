#pragma once

#include <fstream>

#include "IFstream.hpp"

class Fstream : public IFstream
{
public:
	Fstream(const std::string& filePath);
	virtual ~Fstream();

	void tryToWrite(const std::string& content) override;
	std::string tryToRead() override;
protected:
	Fstream() = default;
};