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
			//입력되는 승객의 수
			j++;
	}
	for (int i = 0; i < PC->size(); i++) {
		SC->addPassenger(PC->getPassengerList(i));
	}
	SC->printAllSpot();
	//다른 승객들의 정보를 데이터베이스에 넣는 과정
}
bool Server::getData(string start, string end)
{
	//안녕하세요. " "님?
	//출발지와 도착지를 입력해주세요.
	
	PC->InputPassenger(UC->getList(userNum), start, end);
	//출발지 도착지 입력받고,

	string passengerSpot = start;

	return true;
}

void Server::addPassengerToEvent(Passenger *pass)
{
	for (unsigned int i=0;i<eve.size();i++)
	{	
		//빈 이벤트이면 승객을 삽입
		if (eve.at(i).getSize() == 0)
		{
			eve.at(i).eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
			return;
		}
		else //승객의 출발지를 확인하여 같으면 삽입
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

string Server::sendStartSpotList(Spot *spot) //"출발지:승객A,도착지:승객B,도착지,"
{
	string result = spot->getStartSpot() + ":";
	for (unsigned int i = 0; i < spot->getNumberOfPassenger(); i++) {
		result += spot->getPassengers(i)->getName() + ",";
		result += spot->getPassengers(i)->getDestAddr() + ",";
	}
	return result;
}

string Server::taxiListOfCost(Event* eve)
{
	Handler HD(eve, "Graph.txt");
	string s = HD._calculation->calculate_Compare(HD._graph->originalLength(eve->getPassengerByUserNum(userNum)), eve->getSize() , eve, HD._graph);
	return s;
}
