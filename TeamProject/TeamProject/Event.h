#ifndef EVENT_H
#define EVENT_H
#include "Passenger.h"
#include "Spot.h"


class Event {
public:
	Event();
	void eventAddPassenger(Passenger* pass);
	bool eventDeletePassenger(Passenger* pass);
	void eventOn(Spot* spot);
	string eventPrint(int i);
	void eventEnd();
	void eventSetToPay(int n, int gold);
	int getSize();
	Passenger* getPassenger(int i);
	Passenger* getPassengerByUserNum(int userNumber);

private:
	Passenger passengerOnTaxi[4];
	int size;
};

#endif EVENT_H