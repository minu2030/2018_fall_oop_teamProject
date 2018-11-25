#include "stdafx.h"
#include "passenger.h"
#include <string>

passenger::passenger()
{

}
passenger::passenger(User user)
{
	setName(user.getName());
	setCash(user.getCash());
	setPhoneNumber(user.getPhoneNumber());
}