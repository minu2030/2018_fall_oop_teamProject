#ifndef CALCULATION_H
#define CALCULATION_H

#include "Graph.h"
#include "Event.h"

class Calculation {

	public:

		int calculate_Cost(int length);	//총 비용 계산 함수
		int calculate_Personal_Cost(int total, double percent);	// 개인별 내야할 돈을 계산해준다.
		double calculate_percent(int total, int mine);	//내야할 돈의 비율계산
		int calculate_totalLength(int n, Event* _event, Graph* _graph);	//전체 길이 계산
};

#endif CALCULATION_H