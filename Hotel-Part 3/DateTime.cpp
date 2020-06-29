#include "DateTime.h"

DateTime::DateTime(int day, int month, int year) throw (const string)
{
	try
	{
		if (day < FIRST_DAY || day>LAST_DAY)
			throw "day";
		this->day = day;

		if (month < FIRST_MONTH || day>LAST_MONTH)
			throw "month";
		this->month = (eMonthes)month; //need to check

		if (year < CURRENT_YEAR)
			throw "year";
		this->year = year;

	}
	catch (const char* errMessage)
	{
		cout << "Class:: DateTime: Wrong " << errMessage << "entered.";
	}

}



const eMonthes DateTime::getMonth()
{
	return this->month;
}


const int DateTime::getDay()
{
	return this->day;
}
const int DateTime::getyear() //added const
{
	return this->year;
}


