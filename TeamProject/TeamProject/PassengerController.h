#pragma once
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
	
public:
	PassengerController();
	bool passengerControllerUserInfo(User user,int i,int v);
	Passenger* getPassengerList(int i);
	int returnSize(){ return passengerList.size(); }
};

