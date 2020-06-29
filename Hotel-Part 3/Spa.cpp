#include "Spa.h"

Spa::Spa(const string spaName)
{
	this->spaName.assign(spaName);
}

void Spa::relax() const
{
	std::cout << "Relaxing" << std::endl;
}

void Spa::swim() const
{
	std::cout << "Swimming" << std::endl;
}
