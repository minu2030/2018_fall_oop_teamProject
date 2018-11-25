#ifndef SPOTCONTROLLER_H
#define SPOTCONTROLLER_H
#include "Spot.h"
#include "Passenger.h"

class SpotController {
public:
	SpotController();
	bool addSpot(char* startSpot);
	Spot getSpot(char* startSpot);

private:
	vector<Spot> spots;
	vector<Passenger> passengers;
};
#endif