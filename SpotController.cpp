#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

bool SpotController::addSpot(string startSpot) {
	try {
		if (!isContain(startSpot)) {
			throw "올바르지 않은 출발 장소입니다.";
		}
		Spot *addedSpot = new Spot(startSpot);
		spots.push_back(*addedSpot);
	}
	catch (string errorStr) {
		cout << errorStr << endl;
	}
}

Spot SpotController::getSpot(string startSpot) {
	try {
		for (int i = 0; i < spots.size(); i++) {
			if (isContain(startSpot)) {
				return spots[i];
			}
		}
		throw "해당하는 출발지의 Spot이 없습니다.";
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
}

bool SpotController::isContain(string startSpot)
{
	for (int i = 0; i < spots.size(); i++) {
		if (!strcmp(startSpot.c_str(), spots[i].getStartSpot().c_str())) {
			return true;
		}
	}
	return false;
}

