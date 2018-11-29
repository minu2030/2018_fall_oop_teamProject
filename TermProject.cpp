// TermProject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
#include "stdafx.h"
#include "User.h"
#include "UserController.h"
#include "UserView.h"
#include "PassengerController.h"
#include "PassengerView.h"
#include "SpotController.h"
#include "Spot.h"
#include "SpotView.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
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
		view.printUser(server, i); 
		i++;
	}
	//승객의 정보입력을 시작.

	
	PassengerController PassengerController;
	int _i=0;
	int v = 0;
	//유저의 숫자만큼 승객을 만들기
	//유저의 숫자만큼 배열을 반복

	//유저의 수만큼 loop
	while (_i < server.userSize())
	{
		//승객배열의 index삽입해주기
		if (PassengerController.passengerControllerUserInfo(server.getList(_i), _i, v))
		{
			v++;
		}
		//유저는 반복해서 삽입하여 검사.
		_i++;
	}

	//승객의 정보를 가져올 수 있는 메소드
	//PassengerController.getpassengerList(0);

	PassengerView passengerView;

	int pa = 0;
	while (pa < PassengerController.returnSize())
	{
		passengerView.printPassenger(PassengerController,pa);
		pa++;
	}
	//승객의 정보는 유저번호순으로 입력된다고 가정합니다.
	SpotController spotController;
	SpotView spotView;
	
	spotController.addSpot("속초");
	spotController.getSpot("속초")->addPassenger(PassengerController.getPassengerList(0));
	spotView.printStartSpot(spotController.getSpot("속초"));
	
	spotView.printPassengers(spotController.getSpot("속초"), 0);
	system("pause");
	return 0;
}

