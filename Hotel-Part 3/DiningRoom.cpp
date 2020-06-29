#include "DiningRoom.h"

int DiningRoom::currentAmountOfDiners = 0;
DiningRoom::DiningRoom(int maxNumOfDinners)
{
	this->maxNumOfDinners = maxNumOfDinners;
	currentAmountOfDiners = 0;

}



bool DiningRoom::startMeal(Reservation& res) const throw (const string)
{
	try
	{
		if (res.getPension().getPensionType() == "No Meals")
			throw "This reservation is not allowed to eat in my hotel.";
		if (res.getDinerStatus())
			throw "Reservation is already dining";
		if (currentAmountOfDiners + res.getRoom().getNumOfBeds() > maxNumOfDinners)
			throw "The diner is currently full.";
		currentAmountOfDiners += res.getRoom().getNumOfBeds();
		res.setDinerStatus(true);
		return true;
	}
	catch (string errMsg)
	{
		cout << errMsg;
		return false;
	}
}


void DiningRoom::endMeal(Reservation& res) const throw (const string)
{
	try
	{
		if (!res.getDinerStatus())
			throw "Reservation is not in diner";
		currentAmountOfDiners -= res.getRoom().getNumOfBeds();
		res.setDinerStatus(false);
	}
	catch (string errMsg)
	{
		cout << errMsg;
	}
}


vector<Pension*> DiningRoom::getAllPensionOptions() const
{
	return this->allPension;
}

void DiningRoom::setPensions(vector<Pension*> pensions)
{
	vector<Pension*>::iterator itr = pensions.begin();
	vector<Pension*>::iterator itrEnd = pensions.end();
	for (; itr != itrEnd; ++itr)
	{
		this->allPension.push_back(*itr);
	}
}