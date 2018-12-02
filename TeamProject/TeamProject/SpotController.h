#ifndef SPOTCONTROLLER_H
#define SPOTCONTROLLER_H
#include "Spot.h"
#include "Passenger.h"
#include "string"

using namespace std;
class SpotController {
public:
	SpotController();
	void getSpot(string startSpot);
	void addPassenger(Passenger* pass);
	void deleteSpot(Spot* _spot);
	void printAllSpot();
private:
	vector<Spot> spots;
	vector<Passenger> passengers;
};
#endif