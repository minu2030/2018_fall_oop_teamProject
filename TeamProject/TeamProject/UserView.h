#pragma once
#include "UserController.h"

#include <string>

class UserView 
{
public:
	UserView();
	string printUser(UserController* u,int i);
};

