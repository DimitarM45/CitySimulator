#pragma once

#include <string>

enum class FormatOption
{
	Period = 0,
	ForwardSlash = 1,
	BackwardSlash = 2,
	Dash = 3
};

enum class OrderOption
{
	MDY = 0,
	DMY = 1,
};

// The date class encapsulates day, month and year, methods for moving the date forward and backward, and formatting it as a string.
class Date
{
public:
	Date();
	Date(unsigned short day, unsigned short month, unsigned int year);
	Date(unsigned short day, unsigned short month, unsigned int year, FormatOption formatOption, OrderOption orderOption);

	unsigned short getDay() const;
	unsigned short getMonth() const;
	unsigned int getYear() const;

	const std::string& getDateString() const;

	void moveDateForward(unsigned int days);
	void moveDateBackward(unsigned int days);

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	void format(FormatOption formatOption, OrderOption orderOption);

private:
	unsigned short day;
	unsigned short month;
	unsigned int year;

	std::string dateString;

	FormatOption formattingOptions;
	OrderOption orderOptions;

	void setDay(unsigned short day);
	void setMonth(unsigned short month);
	void setYear(unsigned short year);

	bool isYearLeap(unsigned int year);
	unsigned int getDaysInMonth(unsigned short month);
};

std::ostream& operator<<(std::ostream& outStream, const Date& date);