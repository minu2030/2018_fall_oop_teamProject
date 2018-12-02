#include "PassengerView.h"
using namespace std;
#include <iostream>

PassengerView::PassengerView()
{
}


void PassengerView::printPassenger(PassengerController u, int i)
{
	//유저의 정보를 출력한다.
	cout << " 사용자 이름 : " << u.getPassengerList(i)->getName() << endl;
	cout << " 사용자 전화번호 : " << u.getPassengerList(i)->getPhoneNumber() << endl;
	cout << " Cash : " << u.getPassengerList(i)->getCash() << endl;
	cout << " 출발지 : " << u.getPassengerList(i)->getStartAddr() << endl;
	cout << " 도착지 : " << u.getPassengerList(i)->getDestAddr() << endl;
}

