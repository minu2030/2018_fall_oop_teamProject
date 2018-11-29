#ifndef EVENT_H
#define EVNET_H
#include "Passenger.h"
#include "Spot.h"
class Event {
public:
	Event();

private:
	Passenger passengerOnTaxi[4];
	int size;
	void eventAddPassenger(Passenger* pass);
	void eventOn(Spot* spot);
	void eventPrint();
	void eventEnd();
};

#endif EVENT_H