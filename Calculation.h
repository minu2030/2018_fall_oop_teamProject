#ifndef CALCULATION_H
#define CALCULATION_H

#include "Graph.h"

class Calculation {

	public:

		int calculate_Cost(int length);	//총 비용 계산 함수
		double alloc_Cost(int total, int length);	//내야할 돈의 비율을 계산해준다.
		int calculate_Personal_Cost(int total, double percent);	// 개인별 내야할 돈을 계산해준다.
};

#endif CALCULATION_H