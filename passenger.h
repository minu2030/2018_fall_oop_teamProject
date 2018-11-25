#pragma once
#include <string>
#include "User.h"
using namespace std;

class passenger : public User
{
private:
	string startAddr;
	string destAddr;
	int toPay;
	bool isHost;

public:
	passenger(User user);
	passenger();

	string getStartAddr(){ return startAddr;}
	string getdestAddr(){ return destAddr;}
	int getToPay(){ return toPay; }
	bool getIsHost(){ return isHost; }

	void setStartAddr(string _startAddr){ startAddr = _startAddr; }
	void setdestAddr(string _destAddr){ destAddr = _destAddr; }
	void setToPay(int _toPay){ toPay = _toPay; }
	void setIsHost(bool _isHost){ isHost = _isHost; }
};

