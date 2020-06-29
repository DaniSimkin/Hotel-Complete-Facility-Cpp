#include "Off.h"
#include "on.h"

void On::off(Service& ser) const
{
	ser.setCurrentDiscountState(new Off());
	ser.setServicePrice(ser.getServicePrice()/0.7);
	delete this;
}