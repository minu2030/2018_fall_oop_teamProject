#include "SpotController.h"
#include <cstring>

SpotController::SpotController() {
	spots.reserve(10);
	passengers.reserve(10);
}

bool SpotController::addSpot(char* startSpot) {
	try {
		if (strcmp(startSpot, NULL)) {
			throw "올바르지 않은 출발 장소입니다.";
		}
		Spot *addedSpot = new Spot(startSpot);
		spots.push_back(*addedSpot);
	}
	catch (string errorStr) {
		cout << errorStr << endl;
	}
}

Spot SpotController::getSpot(char* startSpot) {
	try {
		for (int i = 0; i < spots.size(); i++) {
			if (!(strcmp(spots[i].getStartSpot, startSpot))) {
				Spot temp = spots[i];
				//Spots.erase(i);
				return temp;
			}
		}
		throw "해당하는 출발지의 Spot이 없습니다.";
	}
	catch (char* errorStr) {
		cout << errorStr << endl;
	}
}