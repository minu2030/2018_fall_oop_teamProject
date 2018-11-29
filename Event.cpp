#include "Event.h"
using namespace std;
Event::Event()
{
	size = 0;
}

void Event::eventAddPassenger(Passenger* pass)
{
	Passenger* newPass = new Passenger();
	newPass->setName(pass->getName());
	newPass->setPhoneNumber(pass->getPhoneNumber());
	newPass->setCash(pass->getCash());
	newPass->setusernumber(pass->getusernumber());

	passengerOnTaxi[size] = *newPass;
	size++;
}

void Event::eventOn(Spot* spot)
{
	for (int i = 0; i < size; i++) {
		int userNum = passengerOnTaxi->getusernumber();
		delete spot->getPassengersByNum(userNum);
	}
}

void Event::eventPrint()
{
	cout << "목적지에 도착했습니다." << endl;
	for (int i = 0; i < size; i++) {		
		cout << passengerOnTaxi[i].getName() << "님, 지불하실 금액은" << passengerOnTaxi[i].getToPay() << "입니다." << endl;
	}
}

void Event::eventEnd()
{
	for (int i = 0; i < size; i++) {
		delete &passengerOnTaxi[i];
	}
}
