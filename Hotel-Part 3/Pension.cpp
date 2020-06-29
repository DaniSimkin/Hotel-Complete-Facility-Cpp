#include "Pension.h"

Pension::Pension(ePensionType pensionType, int price, bool drinksIncluded): pensionType(pensionType), price(price), drinksIncluded(drinksIncluded){}

const int Pension::getPrice() const
{
	return this->price;
}

bool Pension::areDrinksIncluded() const
{
	return this->drinksIncluded;
}

const string Pension::getPensionType() const
{
	return this->pensionTypes[pensionType];
}

//ADDED NOW

const int Pension::getNumOfPensions() 
{
	return PENSION_TYPES;
}

