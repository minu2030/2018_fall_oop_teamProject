#include "Server.h"
#include <iostream>
using namespace std;
int userNum = 4;

Server::Server()
{
	UC = new UserController();
	PC = new PassengerController(UC->size());
	SC = new SpotController();
	eve.reserve(0);
}

void Server::init()
{
	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
			//ÀÔ·ÂµÇ´Â ½Â°´ÀÇ ¼ö
			j++;
	}
	for (int i = 0; i < PC->size(); i++) {
		SC->addPassenger(PC->getPassengerList(i));
	}
	//´Ù¸¥ ½Â°´µéÀÇ Á¤º¸¸¦ µ¥ÀÌÅÍº£ÀÌ½º¿¡ ³Ö´Â °úÁ¤
}
int Server::getData(string start, string end)
{
	//¾È³çÇÏ¼¼¿ä. " "´Ô?
	//Ãâ¹ßÁö¿Í µµÂøÁö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.
	if (!SC->SpotContain(start))
	{
		return -1;
	}

	if (!SC->SpotContain(end))
	{
		return -2;
	}

	PC->InputPassenger(UC->getList(userNum), start, end);
	//Ãâ¹ßÁö µµÂøÁö ÀÔ·Â¹Ş°í,
	
	Passenger *passenger = new Passenger(UC->getList(userNum));

	passenger->setStartAddr(start);
	passenger->setDestAddr(end);

	SC->addPassenger(passenger);
	
	passengerSpot = start;

	return 1;
}

string Server::proceedEvent()
{
	Spot* tempSpot = SC->getSpot(passengerSpot);

	int temp = 0;
	for (unsigned int i = 0; i < eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
			break;
		}
	}
	eventOn(&eve.at(temp), passengerSpot);

	Handler HD(&eve.at(temp), "C://Users//arabi//Desktop//Graph.txt");
	HD.allocCost(&eve.at(temp));
	return eventEnd(&eve.at(temp));
}

void Server::addPassengerToEvent(Passenger *pass)
{
	for (unsigned int i=0;i<eve.size();i++)
	{	
		//ºó ÀÌº¥Æ®ÀÌ¸é ½Â°´À» »ğÀÔ
		if (eve.at(i).getSize() == 0)
		{
			eve.at(i).eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
			return;
		}
		else //½Â°´ÀÇ Ãâ¹ßÁö¸¦ È®ÀÎÇÏ¿© °°À¸¸é »ğÀÔ
		{
			if ((eve.at(i).getPassenger(0)->getStartAddr() == pass->getStartAddr()) && eve.at(i).getSize() != 4 )
			{
				eve.at(i).eventAddPassenger(pass);
				return;
			}			
		}
	}
	
	Event _eve;
	_eve.eventAddPassenger(pass);
	eve.push_back(_eve);
}
void Server::addPaseengerToEvent(Passenger * pass, Event * _eve)
{
	_eve->eventAddPassenger(pass);
}

void Server::eventOn(Event* eve, string passengerSpot)
{
	eve->eventOn(SC->getSpot(passengerSpot));
}

string Server::eventEnd(Event* eve)
{
	string temp = eve->eventPrint(userNum);
	eve->eventEnd();
	return temp;
}

string Server::proceedBeforeEvent1()
{
	string result = sendStartSpotList(SC->getSpot(passengerSpot));
	return result;
}

string Server::sendStartSpotList(Spot *spot) //"Ãâ¹ßÁö:½Â°´A,µµÂøÁö:½Â°´B,µµÂøÁö,"
{
	string result = "";
	for (unsigned int i = 0; i < spot->getNumberOfPassenger() && i < 4; i++) {
		result += spot->getPassengers(i)->getName() + ",";
		result += spot->getStartSpot() + ",";
		result += spot->getPassengers(i)->getDestAddr() + ":";
	}
	return result;
}

int Server::numOfList()
{
	int temp = SC->getSpot(passengerSpot)->getNumberOfPassenger();
	return temp;
}

string Server::proceedBeforeEvent2()
{
	int temp = 0;
	for (unsigned int i = 0; i<eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
			break;
		}
	}
	string result = taxiListOfCost(&eve.at(temp));
	return result;
}

string Server::taxiListOfCost(Event* eve)
{
	Handler HD(eve, "C://Users//arabi//Desktop//Graph.txt");
	string s = HD._calculation->calculate_Compare(HD._graph->originalLength(eve->getPassengerByUserNum(userNum)), eve->getSize() , eve, HD._graph);
	return s;
}

void Server::makeEvent()
{
	for (int i = 0; i < SC->getSize(); i++) {
		for (unsigned k = 0; k < SC->getSpot(i)->getNumberOfPassenger(); k++) {
			addPassengerToEvent(SC->getSpot(i)->getPassengers(k));
		}
	}
}

void Server::makeEvent2()
{
	int temp = 0;
	for (unsigned i = 0; i < eve.size(); i++) {
		if (eve.at(i).getPassenger(0)->getStartAddr() == passengerSpot) {
			temp = i;
			break;
		}
	}
	addPaseengerToEvent(SC->getSpot(passengerSpot)->getPassengersByUserNum(userNum), &eve.at(temp));
}

