#include "User.h"
#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"

#include <iostream>
int main()
{
	//파일에 있는 유저의 정보를 저장
	UserController server;
	server.ControllerUserInfo();
	//승객을 생성하는 함수
	//server.find();
	UserView view;
	int i=0;

	while (i<5)
	{
		//view.printUser(server, i); 
		i++;
	}
	//승객의 정보입력을 시작.
	PassengerController PassengerController(server.size());

	int _i=0;
	int v = 0;
	//유저의 숫자만큼 승객을 만들기
	//유저의 숫자만큼 배열을 반복
	//유저의 수만큼 loop
	while (_i < server.size())
	{
		//승객배열의 index삽입해주기
		if (PassengerController.passengerControllerUserInfo(server.getList(_i), _i, v))
		{
			v++;
		}
		//유저는 반복해서 삽입하여 검사.
		_i++;
	}

	while (true)
	{
		printf("정보를 입력해주세요");
		int use;
		string st;
		string de;

		cin >> use;
		cin >> st;
		cin >> de;

		PassengerController.InputPassenger(server.getList(use), st, de);
		PassengerView passengerView;

		int pa = 0;
		while (pa < PassengerController.size())
		{
			passengerView.printPassenger(PassengerController, pa);
			pa++;
		}
	}
	
	return 0;
}


