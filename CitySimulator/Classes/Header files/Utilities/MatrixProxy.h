#pragma once

#include <vector>

// The proxy that Matrix<T> uses to simplify indexing. The indexing is done through arithmetic instead of having nested vectors.
template <typename T>
class MatrixProxy
{
public:	
	MatrixProxy(std::vector<T>& data, unsigned yIndex, unsigned width)
		: data(data)
	{
		this->yIndex = yIndex;
		this->width = width;
	}

	const T& operator[](unsigned xIndex) const
	{
		return data.at(yIndex * width + xIndex);
	}

	T& operator[](unsigned xIndex)
	{
		return data.at(yIndex * width + xIndex);
	}

private:
	std::vector<T>& data;
	unsigned yIndex;
	unsigned width;
};

