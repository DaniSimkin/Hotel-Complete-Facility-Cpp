#include "Hotel.h"

Hotel Hotel::theHotel;
Hotel::Hotel()
{

}

Hotel::~Hotel()
{
	/*
	if (!(allReservations == nullptr))
		delete[] allReservations;
	*/

	for (vector<Reservation*>::iterator it = allReservations.begin(); it != allReservations.end(); ++it)
		delete (*it);
	allReservations.clear();

	/*
	if (!(allServices == nullptr))
		delete[] allServices;
		*/

	Node<Room*>* node = allRooms.getHead();
	for (int i = 0; i < numOfRooms -2 && node->getData() !=nullptr; ++i)
	{
		delete node->getData();
		node = node->next;
	}
	allServices.clear();
}

Hotel* Hotel::getInstance()
{
	return &theHotel;
}

void Hotel::setNumOfOccupiedRooms(int num)
{
	this->numOfOccupiedRooms = num;
}

void Hotel::setSpa(Spa& spa)
{
	this->spa = &spa;
}

void Hotel::setDiningRoom(DiningRoom& diningRoom)
{
	this->diningRooom = diningRoom;
}

int Hotel::getNumOfRooms() const
{
	return this->numOfRooms;
}

int Hotel::getNumOfOccupiedRooms() const
{
	return this->numOfOccupiedRooms;
}

int Hotel::getNumOfReservations() const
{
	return this->numOfReservations;
}

int Hotel::getMaxReservationsNum() const
{
	return this->maxReservationsNum;
}
Room& Hotel::getAvailableRoom() const
{
	Node<Room*>* ptr = allRooms.head;
	for (int i = 0; i < numOfRooms; i++)
	{
		if (ptr != nullptr)
		{
			if (!ptr->getData()->getIsOccupied())
			{
				return *ptr->getData();
			}
			ptr = ptr->next;
		}
	}
	cout << "There are no available rooms. Returning first room." << endl;
	return *allRooms.head->getData();
}

Reservation& Hotel::getReservation(int reservationId) const
{
	//return *allReservations[reservationId]; 
	return *(allReservations.at(reservationId));
}

const DiningRoom& Hotel::getDiningRoom() const //NEED TO CHECK THIS
{
	return diningRooom;
}

vector<Service*> Hotel::getAllServices() const
{
	return this->allServices;
}

const Spa& Hotel::getSpa() const
{
	return *this->spa;
}

void Hotel::setAllRooms(LinkedList<Room*> allrooms, int numOfRooms)
{
	this->allRooms = allrooms;
	this->numOfRooms = numOfRooms;
}





void Hotel::addRoom(Room* room) throw (const int)
{
	try
	{
		if (numOfRooms >= maxRoomsNum)
				throw numOfRooms;
		else {
			allRooms.insertToTail(room);
			numOfRooms += 1;

		}
	}
	catch (int numericError)
	{
		cout << "Current amount of rooms is " << numericError << "which is the limit." <<endl;
	}
}


void Hotel::addReservation(Reservation& reservation) throw (const int)
{
	try
	{
		if (numOfReservations >= maxReservationsNum)
			throw numOfReservations;
		else {
			//allReservations[numOfReservations] = &reservation;
			allReservations.insert(allReservations.begin() + numOfReservations, &reservation);
			numOfReservations += 1;
		}

	}
	catch (int numericError)
	{
		cout << "Current reservation num is " << numericError << "which is the limit." <<endl;
	}
}


void Hotel::addService(Service& service) throw (const string) //WORK ON IT NOW
{
	try
		{
			if (numOfServices >= DEDAULT_NUM_OF_SERVICES)
				throw numOfServices;
			else {
				allServices.insert(allServices.begin() + numOfServices, &service);
				numOfServices += 1;
			}

		}
	catch (int numericError)
	{
		cout << "Current add more services: " << numericError << "which is the limit." <<endl;
	}
}

Room& Hotel::operator[](int roomNumber) const
{
	int room = roomNumber % 100;
	Node<Room*>* ptr = allRooms.head;
	for (int i = 1; i < room; i++)
	{
		ptr = ptr->next;
	}
	return *ptr->getData();
}


//ADDED NOW

const string Hotel::getHotelName() const
{
	return this->hotelName;
}

const int Hotel::getMaxRoomNumber() const
{
	return this->maxRoomsNum;
}

vector<Reservation*> Hotel::getAllReservations() const
{
	return this->allReservations;
}

int Hotel::getNumberOfServices() const
{
	return this->numOfServices;
}

int Hotel::getNumberOfReservations() const
{
	return this->numOfReservations;
}



ostream& operator<<(ostream& os, const Hotel& hotel)
{
	int numOfPensions = hotel.getDiningRoom().getAllPensionOptions()[0]->getNumOfPensions();
	int numOfServices = hotel.getNumberOfServices();
	int numOfReservations = hotel.getNumberOfReservations();
	
	os << "Hotel: " << hotel.getHotelName() << " Includes " << hotel.getMaxRoomNumber() << " Rooms, " << hotel.getMaxReservationsNum() << " Reservations, A Dining Room, Spa Rooms, Regular Rooms" << endl
		<< "Our Hotel Also Has A Variety Of Pension Options And Services" << endl << "Our Pensions: " << endl;
	
	for (int i = 0; i < numOfPensions; i++)
	{
		os << "{" << hotel.getDiningRoom().getAllPensionOptions()[i]->getPensionType() << "}" << " Price: " << hotel.getDiningRoom().getAllPensionOptions()[i]->getPrice() << endl;
	}
	
	os << endl << "Our Services At The Moment: " << endl;
	for (int i = 0; i < numOfServices; i++)
	{
		os << "Service Name: " << hotel.getAllServices()[i]->getServiceName() << " Price: " << hotel.getAllServices()[i]->getServicePrice() << endl;
	}

	os << "Existing Reservations: " << hotel.getNumOfReservations() << endl;
	for (int i = 0; i < numOfReservations; i++)
	{
		os << (i+1) + ""<< endl << hotel.getReservation(i);
	}

	return os;
	
}


void Hotel::setHotelStartingDetails(const string hotelName, int maxRoomsNum, int maxReservationsNum)
{
	this->hotelName.assign(hotelName);
	this->maxRoomsNum = maxRoomsNum;
	this->maxReservationsNum = maxReservationsNum;

}



