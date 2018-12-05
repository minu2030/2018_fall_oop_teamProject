#include "Server.h"
#include <iostream>
using namespace std;
int userNum = 4;

Server::Server()
{
	UserController* UC = new UserController();
	PassengerController* PC = new PassengerController(UC->size());
	SpotController* SC = new SpotController();
	SpotView* SV = new SpotView();
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
	SC->printAllSpot();
	//´Ù¸¥ ½Â°´µéÀÇ Á¤º¸¸¦ µ¥ÀÌÅÍº£ÀÌ½º¿¡ ³Ö´Â °úÁ¤
}
bool Server::getData(string start, string end)
{
	//¾È³çÇÏ¼¼¿ä. " "´Ô?
	//Ãâ¹ßÁö¿Í µµÂøÁö¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä.
	
	PC->InputPassenger(UC->getList(userNum), start, end);
	//Ãâ¹ßÁö µµÂøÁö ÀÔ·Â¹Þ°í,
	
	Passenger *passenger = new Passenger(UC->getList(userNum));

	SC->addPassenger(passenger);

	string passengerSpot = start;

	return true;
}

string Server::proceedEvent()
{
	addPassengerToEvent(SC->getSpot(passengerSpot)->getPassengersByUserNum(userNum));
	int temp = 0;
	for (unsigned int i = 0; i < eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
		}
	}
	eventOn(&eve.at(temp), passengerSpot);
	return eventEnd(&eve.at(temp));
}

void Server::addPassengerToEvent(Passenger *pass)
{
	for (unsigned int i=0;i<eve.size();i++)
	{	
		//ºó ÀÌº¥Æ®ÀÌ¸é ½Â°´À» »ðÀÔ
		if (eve.at(i).getSize() == 0)
		{
			eve.at(i).eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
			return;
		}
		else //½Â°´ÀÇ Ãâ¹ßÁö¸¦ È®ÀÎÇÏ¿© °°À¸¸é »ðÀÔ
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
	string result = spot->getStartSpot() + ":";
	for (unsigned int i = 0; i < spot->getNumberOfPassenger(); i++) {
		result += spot->getPassengers(i)->getName() + ",";
		result += spot->getPassengers(i)->getDestAddr() + ",";
	}
	return result;
}

string Server::proceedBeforeEvent2()
{
	int temp = 0;
	for (unsigned int i = 0; i<eve.size(); i++)
	{
		if (eve.at(i).getPassengerByUserNum(userNum)->getusernumber() == userNum) {
			temp = i;
		}
	}
	string result = taxiListOfCost(&eve.at(temp));
	return result;
}

string Server::taxiListOfCost(Event* eve)
{
	Handler HD(eve, "Graph.txt");
	string s = HD._calculation->calculate_Compare(HD._graph->originalLength(eve->getPassengerByUserNum(userNum)), eve->getSize() , eve, HD._graph);
	return s;
}
