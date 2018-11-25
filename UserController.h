#pragma once
#include "User.h"
#include <string>
#include <stdlib.h>
#include <vector>

class UserController
{
private:
	std::vector<User> list;

public:
	UserController();
	void ControllerUserInfo();
	User getList(int i);
	int userSize(){ return list.size(); }
};

