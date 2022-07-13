#include "Date.h"

bool Date::isLeapYear() const
{
	if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
	{
		return true;
	}
	else return false;
}

int Date::monthDays()const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else if (isLeapYear()) return 29;
	else return 28;
}

void Date::nextDate()
{
	if (month == 12 && day == 31)
	{
		month = 1;
		day = 1;
		year++;
	}
	else if (day == monthDays())
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (month == 1 && day == 1)
	{
		month = 12;
		day = 31;
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	struct tm* tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	this->day = tim->tm_mday;
	this->month = 1 + tim->tm_mon;
	this->year = 1900 + tim->tm_year;
	delete tim;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date& obj)
{
	this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
}

Date& Date::operator=(const Date& obj)
{
	this->year = obj.year;
	this->month = obj.month;
	this->day = obj.day;
	return *this;
}

Date::~Date()
{
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getDay() const
{
	return day;
}

void Date::showDate() const
{
	cout << "\nÄàòà: " << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl << endl;
}

bool Date::isValidDate() const
{
	if (month >= 1 && month <= 12 && day >= 1 && day <= monthDays())
	{
		return true;
	}
	else return false;
}

bool Date::operator==(const Date& obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
	{
		return true;
	}
	else return false;
}

bool Date::operator!=(const Date& obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month > obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
	{
		return true;
	}
	else return false;
}

bool Date::operator<(const Date& obj) const&
{
	if (this->year < obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month < obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day < obj.day)
	{
		return true;
	}
	else return false;
}

bool Date::operator>=(const Date& obj) const&
{
	if (this->year >= obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month >= obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day >= obj.day)
	{
		return true;
	}
	else return false;
}

bool Date::operator<=(const Date& obj) const&
{
	if (this->year <= obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month <= obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day <= obj.day)
	{
		return true;
	}
	else return false;
}

Date& Date::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->nextDate();
	}
	return *this;
}

Date& Date::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->prevDate();
	}
	return *this;
}

Date Date::operator+(int n) const&
{
	Date tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

Date Date::operator-(int n) const&
{
	Date tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date Date::operator--() const&
{
	Date tmp = *this;
	tmp.prevDate();
	return *this;
}

Date Date::operator++() const&
{
	Date tmp = *this;
	tmp.nextDate();
	return *this;
}

Date Date::operator--(int n) const&
{
	Date tmp = *this;

	for (int i = 0; i < n; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date Date::operator++(int n) const&
{
	Date tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day / 10 << d.day % 10 << "." << d.month / 10 << d.month % 10 << "." << d.year;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	cout << "Äåíü: ";
	is >> d.day;
	cout << "\nÌåñÿö: ";
	is >> d.day;
	cout << "\nÃîä: ";
	is >> d.year;

	return is;
}
