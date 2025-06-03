#pragma once

#include "MatrixProxy.h"

// The Matrix class is a template for a vector<T> wrapper that uses a proxy (MatrixProxy) for ease of indexing.
template <typename T>
class Matrix
{
public:
	Matrix(unsigned width, unsigned height)
	{
		this->width = width;
		this->data = std::vector<T>(width * height);
	}

	MatrixProxy<T> operator[](unsigned yIndex)
	{
		return MatrixProxy<T>(data, yIndex, width);
	}

	unsigned getSize() const
	{
		return data.size();
	}

private:
	std::vector<T> data;
	unsigned width;
	unsigned height;
};

