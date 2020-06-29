#include "SpaRoom.h"

SpaRoom::SpaRoom(int numOfBeds, int numOfOils)
{
	roomCounter += 1;
	roomNumber = roomCounter;
	setNumOfBeds(numOfBeds);
	isOccupied = false;
}

void SpaRoom::setNumOfOils(int num)
{
	this->numOfOils = num;
}

int SpaRoom::getNumOfOils() const
{
	return this->numOfOils;
}

void SpaRoom::makeAnOilBath() const
{
	cout << "Making an oil bath" << endl;
}