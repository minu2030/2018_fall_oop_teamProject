#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

bool SpotController::addSpot(string startSpot) {
	try {
		if (spots.size() != 0) {
			if (isContain(startSpot)) {
				Spot *addedSpot = new Spot(startSpot);
				spots.push_back(*addedSpot);
				return true;
			}
		}
		else {
			Spot *addedSpot = new Spot(startSpot);
			spots.push_back(*addedSpot);
			return true;
		}
	}
	catch (string errorStr) {
		cout << errorStr << endl;
	}
	return false;
}

Spot* SpotController::getSpot(string startSpot) {
	try {
		for (int i = 0; i < spots.size(); i++) {
			if (isContain(startSpot)) {
				return &spots.at(i);
			}
		}
		throw "해당하는 출발지의 Spot이 없습니다.";
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
	return NULL;
}

bool SpotController::isContain(string startSpot)
{
	for (int i = 0; i < spots.size(); i++) {
		if (strcmp(startSpot.c_str(), spots.at(i).getStartSpot().c_str())) {
			return false;
		}
	}
	return true;
}

