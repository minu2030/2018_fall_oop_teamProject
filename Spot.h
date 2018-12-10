#ifndef SPOT_H
#define SPOT_H
#include "Passenger.h"
#include <vector>
#include <iostream>
#include <string>

class Spot {
public:
	Spot(string startSpot);
	bool addPassenger(Passenger* addedPassenger);
	bool removePassenger(Passenger* removedPassenger);
	Passenger* getPassengers(string passengerName);
	Passenger* getPassengers(int i);
	void setStartSpot(string name);
	string getStartSpot();
	bool check(Passenger* added);
	void erasePassengerByNum(int userNum);
	unsigned int getNumberOfPassenger();
	Passenger* getPassengersByUserNum(int i);

private:
	string startSpot;
	vector<Passenger> passengers;
};
#endif