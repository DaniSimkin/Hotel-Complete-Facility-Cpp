#ifndef INCOMEVISITOR_H
#define INCOMEVISITOR_H

#include "Reservation.h"
#include "ReservationIVisitable.h"

class IncomeVisitor : public IVisitor
{
public:
	IncomeVisitor(int money) : money(money) {}

	virtual void visit(ReservationIVisitable* element)
	{
		Reservation* res = (Reservation*)element;
		res->resLowerPrice(money);
	}
private:
	int money;
};

#endif // !INCOMEVISITOR_H

