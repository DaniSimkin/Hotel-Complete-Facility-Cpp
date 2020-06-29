#ifndef __HOTEL_H
#define __HOTEL_H

#include "Spa.h"
#include "DiningRoom.h"
#include "Room.h"
#include "Reservation.h"
#include "Customer.h"
#include "Service.h"
#include <string>
#include <vector>
#include "LinkedList1.h"

using namespace std;


#define INIT_NUM 0
#define DEDAULT_NUM_OF_SERVICES 100

class Hotel
{
private:

	static Hotel theHotel;
	//Hotel(const Hotel& other);
	Hotel();

	string				hotelName; // V

	int					maxRoomsNum; // V
	int					maxReservationsNum; //V
	int					numOfRooms;
	int					numOfOccupiedRooms;
	int					numOfReservations;
	int					numOfServices; 

	Spa*				spa;
	DiningRoom			diningRooom;
	LinkedList<Room*>	allRooms;
	vector<Service*>	allServices;
	vector<Reservation*> allReservations;


public:

	~Hotel();
	static Hotel* getInstance();

	void addRoom(Room* room) throw (const int); 
	void addReservation(Reservation& reservation) throw (const int);
	void addService(Service& service) throw (const string);

	// setters
	void setNumOfOccupiedRooms(int num);
	void setSpa(Spa& spa);
	void setDiningRoom(DiningRoom& diningRoom);

	// getters
	int getNumOfRooms() const; 
	int getNumOfOccupiedRooms() const; 
	int getNumOfReservations() const; 
	int getMaxReservationsNum() const; 
	Room& getAvailableRoom() const; 
	Reservation& getReservation(int reservationId) const;
	const DiningRoom& getDiningRoom() const;
	vector<Service*> getAllServices() const;
	const Spa& getSpa() const;

	// operators 
	Room& operator[](int roomNumber) const;				
	friend ostream& operator<<(ostream& os, const Hotel& hotel);

	// delete
	
	const Hotel& operator=(const Hotel& hotel) = delete;


	//MINE
	void setAllRooms(LinkedList<Room*> allrooms, int numOfRooms);



	//ADDED NOW
	const string getHotelName() const;
	const int getMaxRoomNumber() const;
	vector<Reservation*> getAllReservations() const;
	int getNumberOfServices() const;
	int getNumberOfReservations() const;

	void setHotelStartingDetails(const string hotelName, int maxRoomsNum, int maxReservationsNum);



	//FOR PART 3 ADDED NOW

	void setAllServices(vector<Service*> allServices);
	void setAllReservations(vector<Reservation*> allReservations);
};

#endif /*!__HOTEL_H*/
