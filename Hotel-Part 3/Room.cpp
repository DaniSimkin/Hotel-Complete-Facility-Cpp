#include "Room.h"

int Room::roomCounter = 0;
Room::Room(int numOfBeds)
{
	roomCounter += 1;
	roomNumber = roomCounter;
	setNumOfBeds(numOfBeds);
	isOccupied = false;

}

int Room::getRoomNumber() const
{
	return this->roomNumber;
}

int	Room::getNumOfBeds() const
{
	return this->numOfBeds;
}

void Room::setNumOfBeds(int num)
{
	this->numOfBeds = num;
}

void Room::setIsOccupied(bool occupied)
{
	this->isOccupied = occupied;
}

bool Room::getIsOccupied() const
{
	return this->isOccupied;
}

bool Room::operator>(const Room& other) const
{
	return this->numOfBeds > other.getNumOfBeds();
}