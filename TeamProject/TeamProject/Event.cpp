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
	newPass->setStartAddr(pass->getStartAddr());
	newPass->setDestAddr(pass->getDestAddr());
	newPass->setToPay(0);
	passengerOnTaxi[size] = *newPass;
	size++;
}

bool Event::eventDeletePassenger(Passenger * pass)
{
	try {
		for (int i = 0; i < 4; i++) {
			if (pass->getusernumber() == passengerOnTaxi[i].getusernumber()) {
				delete &passengerOnTaxi[i];
				return true;
			}
		}
	}
	catch (int excep) {
		throw -1;
	}
}

void Event::eventOn(Spot* spot)
{
	for (int i = 0; i < size; i++) {
		int userNum = passengerOnTaxi->getusernumber();
		delete spot->getPassengersByNum(userNum);
	}
}

string Event::eventPrint(int i)
{
	return (passengerOnTaxi[i].getName() + "님, 지불하실 금액은" + to_string(passengerOnTaxi[i].getToPay()) + " 원입니다.");
}

void Event::eventEnd()
{
	for (int i = 0; i < size; i++) {
		delete &passengerOnTaxi[i];
	}
}

void Event::eventSetToPay(int n, int gold)
{
	passengerOnTaxi[n].setToPay(gold);
}

int Event::getSize() {
	return size;
}

Passenger* Event::getPassenger(int i) {
	return &passengerOnTaxi[i];
}