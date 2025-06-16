#pragma once

#include <string>

class ISerializable
{
public:
	virtual bool serialize(const std::string& fileName) const = 0;

	virtual bool deserialize(const std::string& fileName) const = 0;
};