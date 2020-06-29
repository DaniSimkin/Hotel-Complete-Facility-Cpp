#include "BabySitting.h"


BabySitting::BabySitting(const string serviceName, double price, int maxNumOfChildren, int maxAge, int minAge) :
	Service(serviceName, price), maxNumOfChildren(maxNumOfChildren), maxAge(maxAge), minAge(minAge) {}


bool BabySitting::initService(int numOfChildren, int age ...) const
{

	va_list ap;
	va_start(ap, numOfChildren);
	for (int i = 1; i <= numOfChildren; i++) {
		int a = va_arg(ap, int);
		if (a > maxAge || a < minAge)
			return false;
	}
	return true;

}
