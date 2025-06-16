#pragma once

#include <vector>

#include <Utilities/MatrixProxy.h>

// The Matrix class is a template for a vector<T> wrapper that uses a proxy (MatrixProxy) for ease of indexing.
template <typename T>
class Matrix
{
public:
	Matrix(unsigned width, unsigned length)
	{
		this->width = width;
		this->length = length;
		this->data = std::vector<T>(width * length);
	}

	Matrix(unsigned width, unsigned length, std::vector<T>& data)
		: data(data)
	{
		this->width = width;
		this->length = length;
	}

	MatrixProxy<T> operator[](unsigned yIndex)
	{
		return MatrixProxy<T>(data, yIndex, width);
	}

	unsigned getSize() const
	{
		return data.size();
	}

	unsigned getWidth() const
	{
		return width;
	}

	unsigned getHeight() const
	{
		return length;
	}

private:
	std::vector<T> data;
	unsigned width;
	unsigned length;
};

