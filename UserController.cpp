#include <fstream>
#include <iostream>
#include "UserController.h"
using namespace std;

UserController::UserController()
{
	ControllerUserInfo();
}

void UserController::ControllerUserInfo()
{
	int i = 0;
	fstream infile;
	string _name;
	string _number;
	int _cash;
	infile.open("userInfo.txt");
	while (!infile.eof())
	{
		User* user = new User();
		getline(infile, _name, '\n');
		user->setName(_name);
		getline(infile, _number, '\n');
		user->setPhoneNumber(_number);
		getline(infile, _number, '\n');
		_cash = atoi(_number.c_str());
		user->setCash(_cash);
		user->setusernumber(i);
		list.insert(list.begin() + i,*user);
		i++;
		_size++;
	}	

}

User* UserController::getList(int i)
{
	return &list.at(i);
}

string UserController::printUser(UserController * u, int i)
{
	string result = "";
	result += u->getList(i)->getName() + ",";
	result += u->getList(i)->getPhoneNumber() + ",";
	result += u->getList(i)->getCash() + ",";
	result += u->getList(i)->getusernumber();

	return result;
}
