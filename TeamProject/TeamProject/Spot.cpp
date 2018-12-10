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
		for (unsigned int i = 0; i < passengers.size(); i++) {
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
	for (unsigned int i = 0; i < passengers.size(); i++) {
		if (strcmp (passengers.at(i).getName().c_str(), passengerName.c_str()))
			return &passengers.at(i);
	}
	return nullptr;
}

Passenger* Spot::getPassengers(int i)
{
	return &passengers.at(i);
}

void Spot::setStartSpot(string _startSpot) {
	startSpot = _startSpot;
}

string Spot::getStartSpot()
{
	return startSpot;
}

bool Spot::check(Passenger * added)
{
	if(!strcmp(added->getStartAddr().c_str(), getStartSpot().c_str()))
		return false;
	return true;
}

void Spot::erasePassengerByNum(int userNum)
{
	for (unsigned int i = 0; i < passengers.size(); i++) {
		if (passengers.at(i).getusernumber() == userNum) {
			//Passenger* temp = &passengers.at(i);
			passengers.erase(passengers.begin() + i);
			//delete temp;
		}
	}
}

unsigned int Spot::getNumberOfPassenger()
{
	return passengers.size();
}

Passenger * Spot::getPassengersByUserNum(int userNum) //try_catch로 잡아야함
{
	try {
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers.at(i).getusernumber() == userNum) {
			return &passengers.at(i);
		}
	}
	throw - 1;
	}
	catch (exception e){
		e.what();
	}
}
