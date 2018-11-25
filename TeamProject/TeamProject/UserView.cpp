#include "stdafx.h"
#include "UserView.h"
#include "UserController.h"
#include <iostream>

using namespace std;

UserView::UserView()
{

}
void UserView::printUser(UserController u,int i)
{
	//유저의 정보를 출력한다.
			cout <<" 사용자 이름 : " << u.getList(i).getName() << endl;
			cout << " 사용자 전화번호 : " << u.getList(i).getPhoneNumber() << endl;
			cout << " Cash : " << u.getList(i).getCash() << endl;
}


