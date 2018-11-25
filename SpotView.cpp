#include "SpotView.h"
#include <iostream>
using namespace std;

void SpotView:: printStartSpot(Spot spot) {
	cout << "출발 장소는 : " << spot.getStartSpot() << endl;
}

void SpotView::printPassengers(Spot spot, int i)
{
	cout << i << "번째 승객의 이름은 : " << spot.getPassengers(i).getName << endl;
}
