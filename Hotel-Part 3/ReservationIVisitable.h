#ifndef  RESERVATIONIVISITBALE_H
#define	 RESERVATIONIVISITBALE_H	

class ReservationIVisitable;

class IVisitor
{

public:
	virtual void visit(ReservationIVisitable* element) = 0;
};
class ReservationIVisitable
{
public:
	virtual void accept(IVisitor* visitor) = 0;

};

#endif // ! RESERVATIONIVISITBALE_H

