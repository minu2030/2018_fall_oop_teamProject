#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

Spot* SpotController::getSpot(string startSpot)
{
	for (int i = 0; i < spots.size(); i++) {
		if (startSpot == spots.at(i).getStartSpot()) {
			return &spots.at(i);
		}
	}
}

void SpotController::addPassenger(Passenger * pass)
{
	for (int i = 0; i < spots.size(); i++) {
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
	for (int i = 0; i < spots.size(); i++) {
		if (spots.at(i).getStartSpot() == _spot->getStartSpot()) {
			spots.erase(spots.begin() + i);
		}
	}
}

void SpotController::printAllSpot()
{
	for (int i = 0; i < spots.size(); i++) {
		cout << spots.at(i).getStartSpot() << endl;
	}
}

