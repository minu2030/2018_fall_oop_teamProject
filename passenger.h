#pragma once
#include <string>
#include "User.h"
using namespace std;

class Passenger : public User
{
private:
	string startAddr;
	string destAddr;
	int toPay;
	bool isHost;

public:
	Passenger(User user);
	Passenger();

	string getStartAddr(){ return startAddr;}
	string getdestAddr(){ return destAddr;}
	int getToPay(){ return toPay; }
	bool getIsHost(){ return isHost; }

	void setStartAddr(string _startAddr){ startAddr = _startAddr; }
	void setdestAddr(string _destAddr){ destAddr = _destAddr; }
	void setToPay(int _toPay){ toPay = _toPay; }
	void setIsHost(bool _isHost){ isHost = _isHost; }
};

