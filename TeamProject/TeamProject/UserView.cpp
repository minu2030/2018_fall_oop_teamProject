#include "UserView.h"
#include "UserController.h"
#include <iostream>

using namespace std;

UserView::UserView()
{

}
string UserView::printUser(UserController* u, int i)
{
	string result = "";
	result += u->getList(i)->getName() + ",";
	result += u->getList(i)->getPhoneNumber() + ",";
	result += u->getList(i)->getCash() + ",";
	result += u->getList(i)->getusernumber();

	return result;
}


