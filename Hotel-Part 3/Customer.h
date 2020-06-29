#ifndef Customer_H_
#define Customer_H_

#pragma warning(disable:4996)
#include <string>
using namespace std;
class Reservation;
class Customer
{
private:
	static int		customerCounter;
	int				customerId;
	string			customerName;
	Reservation*	reservation;

public:
	Customer(const string customerName);
	Customer(const Customer&) = delete;

	const int getCustomerId() const;
	const string getCustomerName() const;

	void addReservation(Reservation* reservation);
	Reservation* getReservation() const;
};

#endif /*Customer_H_ */