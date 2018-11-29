#ifndef SPOTCONTROLLER_H
#define SPOTCONTROLLER_H
#include "Spot.h"
#include "Passenger.h"
#include "string"

using namespace std;
class SpotController {
public:
	SpotController();
	bool addSpot(string startSpot);
	Spot* getSpot(string startSpot);
	bool isContain(string startSpot);

private:
	vector<Spot> spots;
	vector<Passenger> passengers;
};
#endif