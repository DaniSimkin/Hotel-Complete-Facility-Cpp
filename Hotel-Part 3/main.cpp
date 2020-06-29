
#pragma warning( disable : 4290 )

#include "Hotel.h"
#include "SpaRoom.h"
#include "BabySittingInRoom.h"
#include <string>
#include <vector>
#include "IncomeVisitor.h"
#define NUM_OF_SERVICES 5
#define NUM_OF_PENSIONS 4
#define NUM_OF_ROOMS 10
using namespace std;

//FOR PART 3



string hotelName = "S&D";
string spaName = "S&D Spa";


int munNumOfDiners = 50;
int maxRoomsNum = 50;
int maxReservationsNum = 100;
double price = 120.0;
int maxNumOfChildren = 6;
int maxAge = 11;
int minAge = 2;
DateTime* startDate;
DateTime* endDate;
DateTime* newDate;
Reservation* r;
Pension* breakfastPension;
Room* room;
//ADDED FOR PART 3

LinkedList<Room*> rooms;
vector<Pension*> pensionVector;
vector<Service*> servicesVector;


void initRooms(Hotel& hotel);
void createRooms(int numOfRooms);
int makeReservation(Customer& customer, Hotel& hotel);
void updateReservation(int reservationId, Hotel& hotel);
void checkIn(int reservationId, Hotel& hotel);
void checkOut(int reservationId, Hotel& hotel);
void getBabySittingService(int reservationId, Hotel& hotel, BabySitting& babySitting);
void getRoomService(int reservationId, Hotel& hotel, RoomService& roomService);
void eatInDiningRoom(int reservationId, Hotel& hotel);
void printHotel(Hotel& hotel);
void deleteObjects();

void newTerminate()
{
	cout << "\nEror.try to catch this exception.\n";
	exit(1);
}

int main()
{
	set_terminate(newTerminate);

	pensionVector.push_back(new Pension(Pension::NO_MEALS));
	pensionVector.push_back(new Pension(Pension::BREAKFAST, 100));
	pensionVector.push_back(new Pension(Pension::BREAKFAST, 100, true));
	pensionVector.push_back(new Pension(Pension::BREAKFAST_AND_DINNER, 200, true));

	// Only a test for STATE DESIGN PATTERN - PLEASE NOTE
	string bolobolo = "BOLOBOLO";
	Service* s1 = new Service (bolobolo, 15.0);
	cout << "Price before discount on " << bolobolo << " service is " << s1->getServicePrice() << endl;
	s1->on();
	cout << "Price after discount on " << bolobolo << " service is " << s1->getServicePrice() << endl;


						// init customer 
	Customer customer("koko"); 


	Customer customer2("Momo"); //ADDED FOR TESTING NOW



						// init hotel
	Hotel* hotel = Hotel::getInstance();
	hotel->setHotelStartingDetails(hotelName, maxRoomsNum, maxReservationsNum);
	initRooms(*hotel);

	
						// init spa
	Spa spa(spaName); 
	hotel->setSpa(spa); // TODO INSIDE HOTEL

					   // init dining room 
	DiningRoom diningRoom(munNumOfDiners); 

	diningRoom.setPensions(pensionVector);

	hotel->setDiningRoom(diningRoom); 

								 // main functionalities
	int reservationId = makeReservation(customer, *hotel);



	int reservationId2 = makeReservation(customer2, *hotel);//ADDED FOR TESTING NOW




	checkIn(reservationId, *hotel);
	updateReservation(reservationId, *hotel);
	eatInDiningRoom(reservationId, *hotel);



	//The girls never use them
	int hoursNum = 4;
	servicesVector.push_back(new Service("towls in room"));
	servicesVector.push_back(new Service("room cleaning"));
	servicesVector.push_back(new RoomService("breakfast in room"));
	servicesVector.push_back(new BabySitting("basic babySitting", price, maxNumOfChildren, maxAge, minAge));
	servicesVector.push_back(new BabySittingInRoom("room babySitting", price, maxNumOfChildren, maxAge, minAge, hoursNum));



	RoomService* roomeService = new RoomService("breakfast in room");
	hotel->addService(*roomeService);
	getRoomService(reservationId, *hotel, *roomeService);

	BabySitting* babySittingService = new BabySitting("basic babySitting", price, maxNumOfChildren, maxAge, minAge);
	hotel->addService(*babySittingService);
	getBabySittingService(reservationId, *hotel, *babySittingService);

	checkOut(reservationId, *hotel);
	printHotel(*hotel);
	system("pause");
	deleteObjects();
	return 0;
}

// init
void initRooms(Hotel& hotel)
{
	// init rooms
	createRooms(NUM_OF_ROOMS);
	//ADDED
	hotel.setAllRooms(rooms, NUM_OF_ROOMS);
}



// main functionalities

void eatInDiningRoom(int reservationId, Hotel& hotel)
{
	hotel.getDiningRoom().startMeal(hotel.getReservation(reservationId));
	hotel.getDiningRoom().endMeal(hotel.getReservation(reservationId));
}

void getRoomService(int reservationId, Hotel& hotel, RoomService& roomService)
{
	//add service to reservation and activate it
	Reservation& r = hotel.getReservation(reservationId);
	r.addService(roomService);
	roomService.activateService(r.getRoom().getRoomNumber());
}

void getBabySittingService(int reservationId, Hotel& hotel, BabySitting& babySitting)
{
	int numOfChildren = 3;
	int age1 = 2;
	int age2 = 4;
	int age3 = 3;

	//add service to reservation and actuvate it
	Reservation& r = hotel.getReservation(reservationId);
	r.addService(babySitting);
	if (babySitting.initService(numOfChildren, age1, age2, age3))
		babySitting.activateService(r.getRoom().getRoomNumber());
}

void checkOut(int reservationId, Hotel& hotel)
{
	hotel.getReservation(reservationId).setStatus(Reservation::FINISHED);
}

void checkIn(int reservationId, Hotel& hotel)
{
	hotel.getReservation(reservationId).setStatus(Reservation::PAID_CHECKED_IN);
}

void updateReservation(int reservationId, Hotel& hotel)
{
	newDate = new DateTime(2, 2, 2019);
	hotel.getReservation(reservationId).setStartDate(*newDate);
}

int makeReservation(Customer& customer, Hotel& hotel)
{
	// make reservation
	startDate = new DateTime(1, 2, 2019);
	endDate = new DateTime(5, 2, 2019);
	int startingPrice = 500;

	breakfastPension = hotel.getDiningRoom().getAllPensionOptions().at(1);
	try {
		Room& room = hotel.getAvailableRoom(); 
		r = new Reservation(customer, room, *breakfastPension, *startDate, *endDate, startingPrice);
		hotel.addReservation(*r);
		customer.addReservation(r);
		room.setIsOccupied(true);
		
		//EACH ODD ROOM NUMBER GETS A DISCOUNT FROM THE VISITOR DESIGN PATTERN
		if (room.getRoomNumber() % 2 == 0)
		{
			cout << "Reservation price before discount: " << r->getTotalPrice()<< endl;
			r->accept(new IncomeVisitor(50));
			cout << "Congratulation you got discount for 50!!!" << endl;
			cout << "Reservation price after discount : " << r->getTotalPrice() << endl;
		}
		return r->getReservationId();
	}
	catch(const string msg){
		cout << "There are no available rooms at this moment." <<endl << msg << endl;
		return 0;
	}	
	
}

void createRooms(int numOfRooms)
{
	int i;
	int regulatBedsNum = 2;
	int spaRoomBedsNum = 3;
	int numOfOils = 3;
	

	try
	{
		for (i = 0; i < numOfRooms - 2; i++)
		{
			room = new Room(regulatBedsNum);
			rooms.insertToTail(room);
		}
		room = new SpaRoom(spaRoomBedsNum);
		rooms.insertToTail(room);
		room = new SpaRoom(spaRoomBedsNum);
		rooms.insertToTail(room);

		
	}
	catch (const string errMessage)
	{
		cout << "Could not create room " << i << ":" << endl << errMessage << endl << endl;
		//numOfRooms = i;
	}

}


void printHotel(Hotel& hotel)
{
	cout << hotel;
}



void deleteObjects() //Please note that some methods that are written in the main are not used.
{                    //Therefore, I am not adding them to this function. This function was not made by the owner.
	for (vector<Pension*>::iterator it = pensionVector.begin(); it != pensionVector.end(); ++it)
		delete (*it);
	pensionVector.clear();

	//delete[] rooms; This one is deleted in the hotel.


}


