#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "PassengerController.h"

using namespace std;

PassengerController::PassengerController()
{
	fstream infile;
	string _startAddr;
	string _destAddr;
	string name;
	int i = 0;
	infile.open("passenger.txt");
	while (!infile.eof())
	{
		passenger passenger;
		getline(infile, name, '\n');
		if (!strcmp(name.c_str(),"NULL"))
		{
			passengerData.insert(passengerData.begin() + i, passenger);
			i++;
			continue;
		}
		getline(infile, _startAddr, '\n');
		passenger.setStartAddr(_startAddr);
		getline(infile, _destAddr, '\n');
		passenger.setdestAddr(_destAddr);
		passengerData.insert(passengerData.begin() + i, passenger);
		i++;
	}
}
bool PassengerController::passengerControllerUserInfo(User user,int i,int v)
{
		passenger passenger(user);
		
		if (passengerData.at(i).getStartAddr() == "")
		{
			return false;
		}
		passenger.setStartAddr(passengerData.at(i).getStartAddr());

		passenger.setdestAddr(passengerData.at(i).getdestAddr());

		passengerlist.insert(passengerlist.begin()+v, passenger);

		return true;

}

passenger PassengerController::getpassengerList(int i)
{
	return passengerlist.at(i);
}