#ifndef BabySittingInRoom_H_
#define BabySittingInRoom_H_

#include "BabySitting.h"
#include "RoomService.h"

class BabySittingInRoom : virtual public BabySitting, virtual public RoomService
{
private:
	int hoursNum;

public:
	BabySittingInRoom(const string serviceName, double price = 150, int maxNumOfChildren = 5, int maxAge = 10, int minAge = 1, int hoursNum = 2);
	

};
#endif /*BabySittingInRoom_H_ */