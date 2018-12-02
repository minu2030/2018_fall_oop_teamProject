#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "SpotView.h"

#include <iostream>

int main()
{
	
	//파일에 있는 유저의 정보를 저장
	UserController* UC = new UserController();
	UserView* UV = new UserView();
	PassengerController* PC = new PassengerController(UC->size());
	PassengerView* PV = new PassengerView();

	for (int i = 0, j = 0; i < UC->size(); i++) {
		if (PC->passengerControllerUserInfo(UC->getList(i), i, j))
			j++;
	}
	//다른 승객들의 정보를 데이터베이스에 넣는 과정
	while (true)
	{
		//안녕하세요. " "님?
		//출발지와 도착지를 입력해주세요.
		
		printf("정보를 입력해주세요");
		int use = 4;
		string st;
		string de;

		cin >> st;
		cin >> de;

		PC->InputPassenger(UC->getList(use), st, de);
		puts("AA");
		int pa = 0;
		while (pa < PC->size())
		{
			PV->printPassenger(PC, pa);
			pa++;
		}
	}
	
	return 0;
}