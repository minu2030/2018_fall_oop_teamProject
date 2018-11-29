#ifndef EVENT_H
#define EVENT_H
#include "Passenger.h"
#include "Spot.h"


class Event {
public:
	Event();
	void eventAddPassenger(Passenger* pass);
	void eventOn(Spot* spot);
	void eventPrint();
	void eventEnd();
	void eventSetToPay(int n, int gold);
	int getSize();
	Passenger* getPassenger(int i);


private:
	Passenger passengerOnTaxi[4];
	int size;
};

#endif EVENT_H