#include "Passenger.h"
#include "Spot.h"
#include <iostream>
#include <string>

using namespace std;
Spot::Spot(string startSpot) {
	setStartSpot(startSpot);
}

bool Spot::addPassenger(Passenger* addedPassenger) {
	try {
		if (check(addedPassenger)) {
			throw "출발지 정보가 같지 않습니다.";
		}
		passengers.push_back(*addedPassenger);
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
		throw "add was Fail";
	}
	return true;
}

bool Spot::removePassenger(Passenger* removedPassenger)
{
	
	try {
		if (passengers.empty()) {
			throw "현재 Passenger가 없습니다.";
		}
		for (int i = 0; i < passengers.size(); i++) {
			if (removedPassenger->getusernumber() == passengers.at(i).getusernumber()) {
				//passengers.erase(removedPassenger);
			}
		}
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
	return false;
}

Passenger* Spot::getPassengers(string passengerName)
{
	for (int i = 0; i < passengers.size(); i++) {
		if (strcmp (passengers.at(i).getName().c_str(), passengerName.c_str()))
			return &passengers.at(i);
	}
	return nullptr;
}

Passenger* Spot::getPassengers(int i)
{
	return &passengers.at(i);
}

Passenger * Spot::getPassengersByNum(int userNum)
{	
	int check = 0;
	for (int i = 0; i < passengers.size(); i++) {
		if (userNum == passengers.at(i).getusernumber()) {
			check = 1;
			return &passengers.at(i);
		}
	}
	if (check == 0) {
		throw "error";
	}
}



void Spot::setStartSpot(string _startSpot) {
	startSpot = _startSpot;
}

string Spot::getStartSpot()
{
	return startSpot;
}

int Spot::getNumOfPassengers()
{
	return passengers.size();
}

bool Spot::check(Passenger * added)
{
	if(!strcmp(added->getStartAddr().c_str(), getStartSpot().c_str()))
		return false;
	return true;
}
