#include "Server.h"
#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int pa = 0;
		while (pa < PC->size())
		{
			PV->printPassenger(PC, pa);
			pa++;
		}
		//puts("현재 같은 출발지에 있는 사람을 모두 출력합니다.");
		Event* eve = new Event();

		string passengerSpot = "기숙사";
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(1));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(2));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(3));
		//입력한 출발지와 같은 출발지의 승객들을 event에 4명까지 추가함
		
		Handler* HD = new Handler(eve, "Graph.txt");

		//사용자에게 보여주는 
		string s = HD->_calculation->calculate_Compare(HD->_graph->originalLength(eve->getPassenger(3)), 4, eve, HD->_graph);
		cout << s << endl;
		puts("동승자 리스트 입니다. 탑승하시겠습니까?");
		if (true) {
			eve->eventOn(SC->getSpot(passengerSpot));
			eve->eventPrint(0);
			eve->eventEnd();
		}
	}
	return 0;
}

Server::Server()
{
	UserController* UC = new UserController();
	UserView* UV = new UserView();
	PassengerController* PC = new PassengerController(UC->size());
	PassengerView* PV = new PassengerView();
	SpotController* SC = new SpotController();
	SpotView* SV = new SpotView();
}

void Server::init()
{
	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
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
	int use = 4;

	PC->InputPassenger(UC->getList(use), start, end);
	
	//출발지 도착지 입력받고,
	return true;
}

void Server::eventOn(Event* eve,string passengerSpot)
{
	eve->eventOn(SC->getSpot(passengerSpot));
}

string Server::eventEnd(Event* eve)
{
	eve->eventPrint(0);
	eve->eventEnd();
}
