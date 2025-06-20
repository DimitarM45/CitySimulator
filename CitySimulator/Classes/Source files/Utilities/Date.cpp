#include <Utilities/Date.h>

#include <ctime>
#include <stdexcept>

constexpr unsigned YEAR_MAX_VALUE = 10000;

namespace DateErrorMessages
{
	const std::string INVALID_MONTH_ERROR_MESSAGE = "Month cannot be less than 1 or more than 12!";
	const std::string INVALID_DAY_ERROR_MESSAGE = "Day cannot be less than 1 or more than 31!";
	const std::string INCORRECT_DAY_ERROR_MESSAGE = "Day is not correct for given month!";
	const std::string INVALID_YEAR_ERROR_MESSAGE = "Year cannot be bigger than " + std::to_string(YEAR_MAX_VALUE) + "!";
}

using namespace DateErrorMessages;

Date::Date()
{
	time_t currentSystemTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentSystemTime);

	day = localTime->tm_mday;
	month = localTime->tm_mon + 1;
	year = localTime->tm_year + 1900;

	format(FormatOption::ForwardSlash, OrderOption::DMY); 
}

Date::Date(unsigned short day, unsigned short month, unsigned int year)
	: Date(day, month, year, FormatOption::ForwardSlash, OrderOption::DMY) {
}

Date::Date(unsigned short day, unsigned short month, unsigned int year, FormatOption formatOption, OrderOption orderOption)
{
	setYear(year);
	setMonth(month);
	setDay(day);

	format(formatOption, orderOption);
}

unsigned short Date::getDay() const
{
	return day;
}

unsigned short Date::getMonth() const
{
	return month;
}

unsigned int Date::getYear() const
{
	return year;
}

const std::string& Date::getDateString() const
{
	return dateString;
}

void Date::moveDateBackward(unsigned int days)
{
	while (days > 0)
	{
		unsigned int daysInMonth = getDaysInMonth(month);

		if (days < day)
		{
			day -= days;

			break;
		}
		else
		{
			days -= day;

			if (month == 1)
			{
				month = 12;
				year--;
			}
			else
			{
				month--;
			}

			day = getDaysInMonth(month);
		}
	}
}

void Date::moveDateForward(unsigned int days)
{
	while (days > 0)
	{
		unsigned int daysInMonth = getDaysInMonth(month);
		unsigned int remainingDays = daysInMonth - day;

		if (days <= remainingDays)
		{
			day += days;

			break;
		}
		else
		{
			days -= (remainingDays + 1);
			day = 1;

			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
			{
				month++;
			}
		}
	}
}

Date& Date::operator++()
{
	moveDateForward(1);

	return *this;
}

Date Date::operator++(int)
{
	Date date = *this;

	moveDateForward(1);

	return date;
}

Date& Date::operator--()
{
	moveDateBackward(1);

	return *this;
}

Date Date::operator--(int)
{
	Date date = *this;

	moveDateBackward(1);

	return date;
}

bool Date::operator==(const Date& other)
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator!=(const Date& other)
{
	return !(*this == other);
}

void Date::format(FormatOption formatOption, OrderOption orderOption)
{
	dateString.clear();

	char separator;

	switch (formatOption)
	{
	case FormatOption::Period:
		separator = '.';
		break;

	case FormatOption::ForwardSlash:
		separator = '/';
		break;

	case FormatOption::BackwardSlash:
		separator = '\\';
		break;

	case FormatOption::Dash:
		separator = '-';
		break;

	default:
		throw std::invalid_argument("Invalid format option!");
		break;
	}

	switch (orderOption)
	{
	case OrderOption::MDY:
		dateString.append(std::to_string(month));
		dateString.append(std::to_string(separator));
		dateString.append(std::to_string(day));
		break;

	case OrderOption::DMY:
		dateString.append(std::to_string(day));
		dateString.append(std::to_string(separator));
		dateString.append(std::to_string(month));
		break;

	default:
		throw std::invalid_argument("Invalid order option!");
		break;
	}

	dateString.append(std::to_string(separator));

	if (year < 10)
	{
		dateString.append("000");
	}
	else if (year < 100)
	{
		dateString.append("00");
	}
	else if (year < 1000)
	{
		dateString.append("0");
	}

	dateString.append(std::to_string(year));
}

void Date::setDay(unsigned short day)
{
	if (day < 1 || day > 31)
		throw std::invalid_argument(INVALID_DAY_ERROR_MESSAGE);

	if (month == 2 && day > 29)
		throw std::invalid_argument(INCORRECT_DAY_ERROR_MESSAGE);

	if (getDaysInMonth(month) != 31 && day > 30)
		throw std::invalid_argument(INCORRECT_DAY_ERROR_MESSAGE);

	this->day = day;
}

void Date::setMonth(unsigned short month)
{
	if (month < 1 || month > 12)
		throw std::invalid_argument(INVALID_DAY_ERROR_MESSAGE);

	this->month = month;
}

void Date::setYear(unsigned short year)
{
	if (year < 1 || year > YEAR_MAX_VALUE)
		throw std::invalid_argument(INVALID_YEAR_ERROR_MESSAGE);

	this->year = year;
}

bool Date::isYearLeap(unsigned int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned int Date::getDaysInMonth(unsigned short month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;

	case 4:
	case 6:
	case 9:
	case 11:
		return 30;

	case 2:
		return isYearLeap(year) ? 29 : 28;

	default:
		return 0;
	}
}

std::ostream& operator<<(std::ostream& outStream, const Date& date)
{
	return outStream << date.getDateString();
}
