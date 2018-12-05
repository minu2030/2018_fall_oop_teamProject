#include "PassengerView.h"
using namespace std;
#include <iostream>

PassengerView::PassengerView()
{
}

//승객의 정보를 출력: "사용자이름,사용자 전화번호,Cash,출발지,도착지"
string PassengerView::printPassenger(PassengerController* u, int i)
{
	string result = "";
	result += u->getPassengerList(i)->getName() + ",";
	result +=  u->getPassengerList(i)->getPhoneNumber() + ",";
	result += u->getPassengerList(i)->getCash() + ",";
	result += u->getPassengerList(i)->getStartAddr() + ",";
	result += u->getPassengerList(i)->getDestAddr();

	return result;
}

