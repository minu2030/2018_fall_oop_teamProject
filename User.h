#pragma once
#include <string>
#include <stdlib.h>
using namespace std;

class User
{
private:
	string name;
	string number;
	int cash;
	int usernumber;

public:
	
	User();
	string getName(){return name;}
	void setName(string _name){name = _name;}
	string getPhoneNumber(){return number;}
	void setPhoneNumber(string num){number = num;}
	int getCash(){return cash;}
	void setCash(int num){ cash = num; }
	int getusernumber(){ return usernumber; }
	void setusernumber(int num){ usernumber = num; }

};


