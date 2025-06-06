#pragma once

#include <vector>
#include <iostream>

template <typename T>
class HistoryManager
{
public:
	HistoryManager(std::ostream& outStream, std::istream& inStream);
	
	const std::vector<T> getCache() const;

	void writeHistory();
private:
	std::ostream& outStream;
	std::istream& inStream;
	unsigned maxCacheSize;
	std::vector<T> cache;

	void readHistory();
};

