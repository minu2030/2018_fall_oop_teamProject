#ifndef CALCULATION_H
#define CALCULATION_H


#include "Graph.h"
#include "Event.h"

using namespace std;

class Calculation {
	public:
		int calculate_Cost(int length);	//총 비용 계산 함수
		int calculate_Personal_Cost(int total, double percent);	// 개인별 내야할 돈을 계산해준다.
		double calculate_percent(int total, int mine);	//내야할 돈의 비율계산
		int calculate_totalLength(int n, Event* _event, Graph* _graph);	//전체 길이 계산
		string calculate_Compare(int myLength, int howMany, Event* _event, Graph* _graph);	//함께탈때,혼자탈때 가격비교해서 string형태로 반환
		int calculate_Length(Graph* g, int start, int dest);
};

#endif CALCULATION_H