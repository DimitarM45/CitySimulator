#pragma once

#include <iostream>

class HistoryManager
{
public:
	HistoryManager(std::ostream& outStream, std::istream& inStream);
	
private:
	std::ostream& outStream;
	std::istream& inStream;
	unsigned maxCacheSize;
};

