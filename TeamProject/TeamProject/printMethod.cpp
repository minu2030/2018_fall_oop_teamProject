#include "printMethod.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

printMethod::printMethod()
{
}

printMethod::~printMethod()
{
}

void printMethod::logo() {//로고 출력
	cout << "                ■■■■                     " << endl;
	cout << "                ■taxi■                     " << endl;
	cout << "          ■■■■■■■■■■               " << endl;
	cout << "        ■        빈차        ■             " << endl;
	cout << "       ■                      ■            " << endl;
	cout << "      ■                        ■           " << endl;
	cout << "   ■■■■■■■■■■■■■■■■■        " << endl;
	cout << "   ■■■    ■■■■■■■    ■■■        " << endl;
	cout << "     ■■    ■■■■■■■    ■■          " << endl;
	cout << "     ■■■■■■■■■■■■■■■          " << endl;
	cout << "     ■■■■■■■■■■■■■■■          " << endl;
	cout << "      ●                        ●           \n" << endl;

}
void printMethod::first() {//환영인사
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "=========WELCOME TO taxihiking==========" << endl;
	cout << "================1:LOGIN=================" << endl;
	cout << "================2:SIGNUP================" << endl;
	cout << "========================================" << endl;
}
void printMethod::start(string* start, string* dest) {//출발지와 도착지를 입력받는다.
	string arrive;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "출발지를 입력해주세요->";
	getline(cin, *start);
	cout << "========================================" << endl;
	cout << "도착지를 입력해주세요->";
	getline(cin, *dest);
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
}
void printMethod::loading() {//파트너를 찾고있는 화면
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========파트너를 찾고 있습니다.=========" << endl;
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
}
void printMethod::moving() {//택시가 이동중인 화면
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "=========택시가  이동중입니다.==========" << endl;
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
}
int printMethod::decide() {//출발할것인지 물어본다
	int decid = 0;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "==========출발  하시겠습니까?===========" << endl;
	cout << "============1:Yes=====2:No==============" << endl;
	cin >> decid;
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
	return decid;
}
bool printMethod::restart() {
	int select=0;
	cout << "다시 시작하시려면 1을 아니면 0을 입력해주세요" << endl;
	cin >> select;
	if (select == 0) {
		return true;
	}
	else {
		return false;
	}
}

void printMethod::notCollectStart(string start) {
	
		cout << start << "는 잘못된 출발지 입력입니다." << endl;
	
}
void printMethod::notCollectDest(string dest) {
	
		cout << dest << "는 잘못된 도착지 입력입니다." << endl;

}
void printMethod::noPeople() {
	cout << "현재 출발하고자 하는 위치에 대기중인 승객이 없습니다." << endl;
}
void printMethod::arrive(string cost) {//도착하여 지불할 금액 출력
	stringstream ss(cost);
	string name, money;
	getline(ss, name, ',');
	getline(ss, money, '\0');
	cout << "========================================" << endl;
	cout << "=========택시가 도착하였습니다==========" << endl;
	cout << "========================================" << endl;
	cout << "====="<<name<<"님! 지불할 요금은" << money << "원입니다.======" << endl;
	cout << "========================================" << endl;
	cout << "============안녕히 가세욤~♥============" << endl;
	cout << "========================================\n" << endl;
}
void printMethod::find() {//파트너를 찾음
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "=========파트너를  찾았습니다.==========" << endl;
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
}
void printMethod::check(string start, string dest) {//입력한 출발지와 도착지 확인

	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "============출발지:" << start << "===============" << endl;
	cout << "============도착지:" << dest << "===============" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================\n" << endl;
}

void printMethod::showlist(string list) {//출발지가 같은 파트너를 보여준다.
	int count = 1;
	stringstream ss(list);
	string temp, name, start, dest;
	cout << "========파트너가 매칭되었습니다.==========" << endl;
	while (getline(ss, temp, ':')) {
		stringstream s(temp);
		getline(s, name, ',');
		getline(s, start, ',');

		getline(s, dest, ',');
		cout << count << "  이름 : " << name << "  출발지 : " << start << "  도착지 : " << dest << endl;
		count++;
	}
	cout << "========================================\n" << endl;

}
void printMethod::buddy(string friends) {//파트너들의 도착지와 예상 금액을 출력한다.
	cout << "========================================" << endl;
	cout << friends;
	cout << "\n========================================\n" << endl;
}


