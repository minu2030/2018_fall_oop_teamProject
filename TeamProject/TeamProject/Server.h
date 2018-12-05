#pragma once
#include "UserController.h"
#include "PassengerController.h"
#include "SpotController.h"
#include "SpotView.h"
#include "Handler.h"
#include <iostream>

class Server
{
private:
	UserController* UC;
	PassengerController* PC;
	SpotController* SC;
	SpotView* SV;
	//Event* eve;
	vector<Event> eve;
	string passengerSpot;

public:
	Server();
	~Server();
	void init(); //데이터베이스 불러오는 역할
	bool getData(string start, string end); //출도착지 입력받기
	void addPassengerToEvent(Passenger * pass);
	string sendStartSpotList(Spot* spot); //같은 출발지의 passenger의 "이름, 출발지, 도착지:이름, 출발지, 도착지" 이름은 A,B 등 가명처리
	string taxiListOfCost(Event* eve); //같이 타는 사람들의 도착지와 혼자 가게 될 경우 낼 금액과 같이 타게될 경우의 금액						   //"A:도착지, B:도착지, C:도착지, 혼자 금액, 같이 타면 금액"
	void eventOn(Event* eve, string passengerSpot); //출발하게 되면 출발 스팟의 리스트에서 해당 사용자들을 삭제
	string eventEnd(Event* eve); //이름 고객님, ~나왔습니다. "현재 유저의 이름, 낼 금액"
};