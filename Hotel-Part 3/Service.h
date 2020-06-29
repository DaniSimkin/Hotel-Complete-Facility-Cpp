#ifndef Service_H_
#define Service_H_

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class ServiceDiscountState;

class Service
{
private:
	double	price;
	string	serviceName;
	ServiceDiscountState* currDiscState;

public:

	void setCurrentDiscountState(ServiceDiscountState* ser) { currDiscState = ser; }
	void on();
	void off();
	void setServicePrice(double price);



	Service(const string serviceName = "", double price = 0); //ADDED "" AS THERE WAS NO DEFAULT CONSTRUCTOR
	Service(const Service&) = delete;
	
	virtual void activateService(const int roomNumber) const;

	//ADDED NOW

	const string getServiceName() const;
	const double getServicePrice() const;

};
#endif /*Service_H_ */