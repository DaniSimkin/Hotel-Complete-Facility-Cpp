#include "Service.h"
#include "ServiceDiscountState.h"
#include "on.h"
#include "Off.h"


Service::Service(const string serviceName, double price) : currDiscState(new Off())
{
	this->serviceName = serviceName;
	this->price = price;
}

void Service::activateService(const int roomNumber) const
{
	std::cout << "Starting " << "service" << " at room " << roomNumber << std::endl; // to fix print service name
}


//ADDED NOW

const string Service::getServiceName() const
{
	return this->serviceName;
}
const double Service::getServicePrice() const
{
	return this->price;
}

void Service::setServicePrice(double price)
{
	this->price = price;
}

void Service::on() 
{
	currDiscState->on(*this);
}

void Service::off() 
{
	currDiscState->off(*this);
}



