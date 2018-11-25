#ifndef SPOT_H
#define SPOT_H
#include "Passenger.h"
#include <vector>
#include <iostream>
#include <string>

class Spot {
public:
	Spot(char* startSpot);
	bool addPassenger(Passenger* addedPassenger);
	bool removePassenger(Passenger* removedPassenger);
	Passenger getPassengers(string passengerName);
	Passenger getPassengers(int i);
	void setStartSpot(char* name);
	string getStartSpot();
	int getNumOfPassengers();

private:
	//const static int DEFAULT_CAPACITY = 10;
	string startSpot;
	vector<Passenger> passengers;
};
#endif