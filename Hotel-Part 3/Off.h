#ifndef OFF_H
#define OFF_H

#include "ServiceDiscountState.h"

class Off : public ServiceDiscountState
{
public:
	Off() {}
	~Off() {}
	virtual void on(Service& ser) const;
};



#endif // !OFF_H
