#pragma once
#pragma once
#include "passenger.h"
#include <string>
#include <stdlib.h>
#include <vector>

class PassengerController
{

private:
	std::vector<passenger> passengerData;
	std::vector<passenger> passengerlist;
	
public:
	PassengerController();
	bool passengerControllerUserInfo(User user,int i,int v);
	passenger getpassengerList(int i);
	int returnSize(){ return passengerlist.size(); }
};

