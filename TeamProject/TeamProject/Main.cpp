#include "Server.h"
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include "login.h"
#include "printMethod.h"

using namespace std;

int main()
{
	Server server;
	server.init();
	login log;
	printMethod prin;
	int select = 0;
	bool loginfound = false;
	prin.logo();
	prin.first();
	cin >> select;
	if (select == 2) {
		log.signup();
	}
	while (!loginfound) {
		loginfound = log.islogin();
	}
	if (loginfound) {

		string start, dest;
		int cycle = 0;
		for (; ; cycle++)
		{
			prin.start(&start, &dest);
			prin.check(start, dest);
			int checkList = server.getData(start, dest);
			if (checkList == -1) {
				prin.notCollectStart(start);
				continue;
			}
			else if (checkList == -2) {
				prin.notCollectDest(dest);
				continue;
			}
			prin.loading();
			Sleep(3000);
			checkList = server.numOfList();
			if (checkList == 1) {
				prin.noPeople();
				continue;
			}
			string show1 = server.proceedBeforeEvent1();
			prin.showlist(show1);
			prin.find();
			if (cycle == 0)
				server.makeEvent();
			else {
				server.makeEvent2();
			}
			string show2 = server.proceedBeforeEvent2();

			prin.buddy(show2);
			if (prin.decide() == 1) {
				prin.moving();
				Sleep(5000);
				string show3 = server.proceedEvent();
				prin.arrive(show3);
			}

			if (prin.restart()) {
				break;
			}
			cin.ignore();
		}
	}
}