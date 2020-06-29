#ifndef _SERVICEDISCOUNTSTATE_H
#define _SERVICEDISCOUNTSTATE_H

#include <iostream>
using namespace std;

#include "Service.h"

class ServiceDiscountState
{
public:
	virtual void on(Service& ser) const
	{
		cout << "The Service gets a 30% off discount";
	}

	virtual void off(Service& ser) const
	{
		cout << "No Discount on the service";
	}

};

#endif // !_SERVICEDISCOUNTSTATE_H

