#include "Customer.h"
int Customer::customerCounter = 0;
Customer::Customer(const string customerName)
{
	this->customerName.assign(customerName);
	customerCounter += 1;
	customerId = customerCounter;
}

const int Customer::getCustomerId() const
{
	return this->customerId;
}

const string Customer::getCustomerName() const
{
	return this->customerName;
}
void Customer::addReservation(Reservation* reservation)
{
	this->reservation = reservation;
}

Reservation* Customer::getReservation() const
{
	return this->reservation;
}
