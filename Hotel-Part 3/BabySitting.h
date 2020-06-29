#ifndef BabySitting_H_
#define BabySitting_H_

#include "Service.h"
#include<stdarg.h>

class BabySitting : virtual public Service
{
private:
	int maxNumOfChildren;
	int maxAge;
	int minAge;

public:
	BabySitting(const string serviceName, double price = 150, int maxNumOfChildren = 5, int maxAge = 10, int minAge = 1);

	bool initService(int numOfChildren, int age ...) const;

};
#endif /*BabySitting_H_ */