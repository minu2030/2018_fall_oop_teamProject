#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "UserController.h"
using namespace std;

UserController::UserController()
{

}

void UserController::ControllerUserInfo()
{
	int i = 0;
	fstream infile;
	string _name;
	string _number;
	int _cash;
	infile.open("C:/Users/rlajd/Desktop/userInfo.txt");
	while (!infile.eof())
	{
		User user;
		getline(infile, _name, '\n');
		user.setName(_name);
		getline(infile, _number, '\n');
		user.setPhoneNumber(_number);
		getline(infile, _number, '\n');
		_cash = atoi(_number.c_str());
		user.setCash(_cash);
		user.setusernumber(i);
		list.insert(list.begin() + i,user);
		i++;
		_size++;
	}

}

User UserController::getList(int i)
{
	return list.at(i);
}