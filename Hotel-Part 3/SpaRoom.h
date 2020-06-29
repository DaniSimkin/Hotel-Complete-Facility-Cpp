#ifndef SpaRoom_H_
#define SpaRoom_H_

#include "Room.h"
#include <iostream>
using namespace std;
class SpaRoom : virtual public Room
{
private:
	int numOfOils;

public:
	SpaRoom(int numOfBeds = 1, int numOfOils = 1);

	int getNumOfOils() const;
	void setNumOfOils(int num);

	void makeAnOilBath() const;
};

#endif /*SpaRoom_H_ */