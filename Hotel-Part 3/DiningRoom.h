#ifndef DiningRoom_H_
#define DiningRoom_H_

#include "Reservation.h"
#include "Pension.h"
#include <vector>
#define DEFAULT_AMOUNT_OF_DINERS 50


class DiningRoom
{
private:
	int			maxNumOfDinners;										// max num of people that can eat at the same time
	static int	currentAmountOfDiners;
	vector<Pension*>	allPension;


public:
	DiningRoom(int maxNumOfDinners = DEFAULT_AMOUNT_OF_DINERS);
	DiningRoom(const DiningRoom&) = delete;
	bool startMeal(Reservation& res) const throw (const string);	// start meal if currentNumOfDinners < maxNumOfDinners
	void endMeal(Reservation& res) const throw (const string);

	//void addPension(const Pension& pension) throw (const string);	// add pension to the diningRoom //Not needed since it will require a dynamic allocation.(Refer to Word file)
	void setPensions(vector<Pension*> pensions);

	vector<Pension*>	getAllPensionOptions() const;
};

#endif /*DiningRoom_H_ */