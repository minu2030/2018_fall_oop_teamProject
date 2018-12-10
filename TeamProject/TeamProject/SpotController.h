#ifndef SPOTCONTROLLER_H
#define SPOTCONTROLLER_H
#include "Spot.h"
#include "Passenger.h"
#include "string"

using namespace std;
class SpotController {
public:
	SpotController();
	Spot* getSpot(string startSpot);
	Spot* getSpot(int index);
	void addPassenger(Passenger* pass);
	void deleteSpot(Spot* _spot);
	void printAllSpot();
	int getSize();
	bool SpotContain(string s);
private:
	vector<Spot> spots;
	vector<Passenger> passengers;
	string spotList[10] = {"기숙사","월평역","유성온천역","카이스트","대전역","복합터미널","월드컵경기장","봉명동","은행동","둔산동"};
};
#endif