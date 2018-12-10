#include "login.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

login::login()
{
}


login::~login()
{
}
void login::signup()
{
	string id, password;
	cout << "ID : ";
	cin >> id;
	cout << "PASSWORD : ";
	cin >> password;
	ofstream writeFile("C:\\Users\\arabi\\Desktop\\2018_fall_oop_teamProject\\TeamProject\\TeamProject\\sign.txt", ios::app);
	if (writeFile.is_open()) {
		writeFile << id;
		writeFile << ',';
		writeFile << password;
		writeFile << '\n';
		writeFile.close();
	}
};
bool login::islogin() {
	string temp1, temp2,id,pass;
	ifstream readFile;
	cout << "로그인을 해주세요!\nID :";
	cin >> id;
	cout << "PASSWORD : ";
	cin >> pass;

	readFile.open("C:\\Users\\arabi\\Desktop\\2018_fall_oop_teamProject\\TeamProject\\TeamProject\\sign.txt");
	while (!readFile.eof()) {

		getline(readFile, temp1, ',');
		getline(readFile, temp2, '\n');
		if (id==temp1 && pass==temp2) {
			cin.ignore();
			cout << "로그인 성공!"<<endl;
			return true;
		}
	}
	cout << "회원이 아닙니다." << endl;
	return false;
}
	

