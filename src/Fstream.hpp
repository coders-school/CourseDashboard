#pragma once

#include <fstream>
#include "IFstream.hpp"

class Fstream : public IFstream
{
public:
	Fstream(const std::string& filePath);

	void tryToWrite(const std::string& content) const override;
	std::string tryToRead() const override;
	std::string getFilePath() const override;

private:
	std::string filePath_;
};