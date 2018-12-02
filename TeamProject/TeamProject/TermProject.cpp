#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "SpotView.h"
#include "Handler.h"
#include <iostream>

int main()
{
	
	//파일에 있는 유저의 정보를 저장
	UserController* UC = new UserController();
	UserView* UV = new UserView();
	PassengerController* PC = new PassengerController(UC->size());
	PassengerView* PV = new PassengerView();
	SpotController* SC = new SpotController();
	SpotView* SV = new SpotView();


	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
			j++;
	}

	for (int i = 0; i < PC->size(); i++) {
		SC->addPassenger(PC->getPassengerList(i));
	}
	SC->printAllSpot();
	//다른 승객들의 정보를 데이터베이스에 넣는 과정

	while (true)
	{
		//안녕하세요. " "님?
		//출발지와 도착지를 입력해주세요.
		
		printf("정보를 입력해주세요");
		int use = 4;
		string st;
		string de;

		//cin >> st;
		//cin >> de;

		PC->InputPassenger(UC->getList(use), st, de);
		//출발지 도착지 입력받고,
		/*
		int pa = 0;
		while (pa < PC->size())
		{
			PV->printPassenger(PC, pa);
			pa++;
		}
		*/

		//puts("현재 같은 출발지에 있는 사람을 모두 출력합니다.");
		Event* eve = new Event();
		string passengerSpot = "기숙사";
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(0));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(1));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(2));
		eve->eventAddPassenger(SC->getSpot(passengerSpot)->getPassengers(3));
		//입력한 출발지와 같은 출발지의 승객들을 event에 4명까지 추가함
		
		Handler* HD = new Handler(eve, "Graph.txt");
		
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