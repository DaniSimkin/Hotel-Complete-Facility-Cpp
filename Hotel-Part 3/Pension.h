#ifndef Pension_H_
#define Pension_H_
#define PENSION_TYPES 4
#include <iostream>
using namespace std;

class Pension
{
public:
	const string pensionTypes[PENSION_TYPES] = { "No Meals","Breakfast","Dinner","Breakfast and Dinner" };
	enum ePensionType { NO_MEALS, BREAKFAST, DINNER, BREAKFAST_AND_DINNER };

	Pension(ePensionType pensionType = NO_MEALS, int price = 0, bool drinksIncluded = false);

	const int getPrice() const;
	bool areDrinksIncluded() const;
	const string getPensionType() const;

	//ADDED NOW
	const int getNumOfPensions();


private:
	ePensionType	pensionType;
	int				price;
	bool			drinksIncluded;
};
#endif /*Pension_H_ */
