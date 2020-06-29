#ifndef _ON_H
#define _ON_H
#include "ServiceDiscountState.h"

class On : public ServiceDiscountState
{
public:
	On(){ }
	~On(){}
	virtual void off(Service& ser) const;
};




#endif // !_ON_H

