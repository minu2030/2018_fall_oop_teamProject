#include <fstream>
#include <iostream>
#include "PassengerController.h"
#include "UserController.h"

using namespace std;

//기존 승객정보 업로드
PassengerController::PassengerController(int size)
{
	fstream infile;
	string _startAddr;
	string _destAddr;
	string name;
	_size = 0;
	int i = 0;
	infile.open("passenger.txt");
	while (!infile.eof())
	{
		Passenger passenger;
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
		passenger.setDestAddr(_destAddr);
		passengerData.insert(passengerData.begin() + i, passenger);
		i++;
	}

	passengerData.reserve(size);
}

//user의 정보를 받아 승객을 생성하는 과정
bool PassengerController::passengerControllerUserInfo(User* user,int i,int v)
{
		Passenger passenger(*user);
		
		if (passengerData.at(i).getStartAddr() == "")
		{
			return false;
		}
		passenger.setStartAddr(passengerData.at(i).getStartAddr());

		passenger.setDestAddr(passengerData.at(i).getDestAddr());

		passengerList.insert(passengerList.begin()+v, passenger);

		_size++;
		return true;
}

//승객리스트를 다른 클래스로 전달하기 위한 함수
Passenger* PassengerController::getPassengerList(int i)
{
	return &passengerList.at(i);
}

//UI에서 승객의 정보를 입력받기 위한 함수
void PassengerController::InputPassenger(User* user, string start, string dest)
{
	Passenger passenger(*user);
	int boolean = 0;
	passenger.setStartAddr(start);
	passenger.setDestAddr(dest);
	//유저번호에 맞게 입력된 정보를 저장한다.
	passengerData.insert(passengerData.begin() + user->getusernumber(), passenger);
		for (int i = 0; i < passengerList.size();i++)
		{
			if (passengerList.at(i).getusernumber() == user->getusernumber())
			{
				passengerList.erase(passengerList.begin() + i);
				passengerList.insert(passengerList.begin() + i, passenger);
				boolean = 1;
			}
		}
		if (boolean == 0){
			_size++;
			passengerList.push_back(passenger);
		}
}

string PassengerController::printPassenger(PassengerController* u, int i)
{
	string result = "";
	result += u->getPassengerList(i)->getName() + ",";
	result += u->getPassengerList(i)->getPhoneNumber() + ",";
	result += u->getPassengerList(i)->getCash() + ",";
	result += u->getPassengerList(i)->getStartAddr() + ",";
	result += u->getPassengerList(i)->getDestAddr();

	return result;
}