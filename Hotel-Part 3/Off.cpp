#include "Off.h"
#include "on.h"

void Off::on(Service& ser) const
{
	ser.setCurrentDiscountState(new On());
	ser.setServicePrice(ser.getServicePrice() * 0.7);
	delete this;
}