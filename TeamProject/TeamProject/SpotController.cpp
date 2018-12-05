#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

Spot* SpotController::getSpot(string startSpot)
{
	try {
		for (unsigned int i = 0; i < spots.size(); i++) {
			if (startSpot == spots.at(i).getStartSpot()) {
				return &spots.at(i);
			}
		}
		throw - 1;
	}
	catch (exception exept) {
		cout << exept.what() << endl;
	}
}

void SpotController::addPassenger(Passenger * pass)
{
	for (unsigned int i = 0; i < spots.size(); i++) {
		if (pass->getStartAddr() == spots.at(i).getStartSpot()) {
			spots.at(i).addPassenger(pass);
			return;
		}
	}
	Spot* _spot = new Spot(pass->getStartAddr());
	_spot->addPassenger(pass);
	spots.push_back(*_spot);
}

void SpotController::deleteSpot(Spot * _spot)
{
	for (unsigned int i = 0; i < spots.size(); i++) {
		if (spots.at(i).getStartSpot() == _spot->getStartSpot()) {
			spots.erase(spots.begin() + i);
		}
	}
}

void SpotController::printAllSpot()
{
	for (unsigned int i = 0; i < spots.size(); i++) {
		cout << spots.at(i).getStartSpot() << endl;
	}
}

