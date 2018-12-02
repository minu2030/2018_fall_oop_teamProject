#pragma once
#include "User.h"
#include <string>
#include <stdlib.h>
#include <vector>

class UserController
{
private:
	std::vector<User> list;
	int _size;

public:
	UserController();
	int size(){ return _size; }
	void ControllerUserInfo();
	User* getList(int i);
};

