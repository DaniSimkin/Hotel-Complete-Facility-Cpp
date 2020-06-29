#ifndef RoomService_H_
#define RoomService_H_

#include "Service.h"

class RoomService : virtual public Service
{
public:
	RoomService(const string serviceName = "", int price = 100);
};
#endif /*RoomService_H_ */