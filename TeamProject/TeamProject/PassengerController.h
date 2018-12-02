#pragma once
#include "passenger.h"
#include <string>
#include <stdlib.h>
#include <vector>

class PassengerController
{

private:
	std::vector<Passenger> passengerData;
	std::vector<Passenger> passengerList;
	int _size;
	
public:
	PassengerController(int size);
	int size(){ return _size; }
	bool passengerControllerUserInfo(User user,int i,int v);
	Passenger* getPassengerList(int i);
	void InputPassenger(User user,string start,string dest);

};

