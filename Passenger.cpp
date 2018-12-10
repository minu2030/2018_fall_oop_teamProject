#include "Passenger.h"
#include <string>

Passenger::Passenger()
{

}
Passenger::Passenger(User* user)
{
	setName(user->getName());
	setCash(user->getCash());
	setPhoneNumber(user->getPhoneNumber());
	setusernumber(user->getusernumber());
}