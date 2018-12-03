#include "Handler.h"


Handler:: Handler(Event* event, string graphAddr) {	//생성자
	Graph* forMake = new Graph(10);
	_graph = forMake->makeGraph(graphAddr);	//그래프 만들기
	_event = event;
	_calculation = new Calculation();
}

Handler:: ~Handler(void) {			//소멸자
	_graph->~Graph();	//그래프 삭제
}


void Handler::allocCost(Event* _event) {
	int size = _event->getSize();
	int totalLength = 0;
	int minLength = 0;
	int totalCost = 0;

	if (size == 2) {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1));	//최단 거리계산
	}
	else if (size == 3) {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1), _event->getPassenger(2));	//최단 거리계산
	}
	else {
		minLength = _graph->findMinWay(_event->getPassenger(0), _event->getPassenger(1), _event->getPassenger(2),
			_event->getPassenger(3));	//최단 거리계산
	}

	totalCost = _calculation->calculate_Cost(minLength);	//총 요금계산
	totalLength = _calculation->calculate_totalLength(size, _event, _graph);	//총길이 계산


	for (int i = 0; i < size; i++) {
		int myLength = _graph->originalLength(_event->getPassenger(i));	//본인 길이저장
		double percent = _calculation->calculate_percent(totalLength, myLength);	//내가낼 비율계산
		int toPay = _calculation->calculate_Personal_Cost(totalCost, percent);
		
		_event->eventSetToPay(i, toPay);	//passenger에 topay를 넣어준다.
	}
}


