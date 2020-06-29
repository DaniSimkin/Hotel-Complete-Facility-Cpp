#ifndef ROOM_H_
#define ROOM_H_

class Room
{
protected:
	static int	roomCounter;
	int			roomNumber;
	int			numOfBeds;
	bool		isOccupied;

public:
	Room(int numOfBeds = 1);

	int	 getRoomNumber() const;
	int	 getNumOfBeds() const;

	void setNumOfBeds(int num);
	void setIsOccupied(bool occupied);

	bool getIsOccupied() const;
	bool operator>(const Room& other) const;

};

#endif /*ROOM_H_ */