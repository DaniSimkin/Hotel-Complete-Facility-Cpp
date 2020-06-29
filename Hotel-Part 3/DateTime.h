
#ifndef DATETIME_H_
#define DATETIME_H_
#include <iostream>

#define FIRST_DAY 1
#define LAST_DAY 31
#define FIRST_MONTH 1
#define LAST_MONTH 12
#define CURRENT_YEAR 2019
using namespace std;
#pragma warning( disable : 4290 )
enum eMonthes
{
	January = 1,
	Februbary = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};


class DateTime
{
private:
	int 							year;
	int								day;
	eMonthes 						month;

public:
	DateTime(int day = FIRST_DAY, int month = FIRST_MONTH, int year = CURRENT_YEAR) throw (const string);
	const eMonthes   getMonth();
	const int	     getDay();
	const int	     getyear();
};

#endif /* DATETIME_H_ */
