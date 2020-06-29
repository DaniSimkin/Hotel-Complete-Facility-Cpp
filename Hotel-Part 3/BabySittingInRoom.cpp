#include "BabySittingInRoom.h"


BabySittingInRoom::BabySittingInRoom(const string serviceName, double price, int maxNumOfChildren, int maxAge, int minAge, int hoursNum)
	:BabySitting(serviceName, price*hoursNum, maxNumOfChildren, maxAge, minAge) {}

