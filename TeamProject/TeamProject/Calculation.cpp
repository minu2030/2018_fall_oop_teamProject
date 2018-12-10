#include "Calculation.h"


int Calculation::calculate_Cost(int length) {	//총 비용 계산 함수( 1km당 900원으로 계산)
	return 900 * length;
}

int Calculation::calculate_Length(Graph* g, int start, int dest) {
	return g->matrixValue(start, dest);
}


string Calculation::calculate_Compare(int myLength, int howMany, Event* _event, Graph* _graph) {
	int alone = calculate_Cost(myLength);
	int with = 0;

	int dest1_Cost = 0;
	int dest2_Cost = 0;
	int dest3_Cost = 0;
	string start = _event->getPassenger(0)->getStartAddr();


	string dest1 = "";
	
	string dest2 = "";
	
	string dest3 = "";


	int size = howMany;
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

	totalCost = calculate_Cost(minLength);	//총 요금계산
	totalLength = calculate_totalLength(size, _event, _graph);	//총길이 계산
	double percent = calculate_percent(totalLength, myLength);	//내가낼 비율계산
	
	/*
	dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));

	dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));

	dest3_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest3));
	*/

	switch (howMany) {
	case 2: 
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		with = alone + calculate_Cost(dest1_Cost);
		return ("함께가는 사람들의 도착지 : " + dest1 + "\n" + "혼자갈때의 예상 요금 : " + to_string(alone) + "\n" + "함께갈때의 예상 요금 : " + to_string((int)(totalCost * percent)));
	case 3:
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));
		with = alone + calculate_Cost(dest1_Cost) + calculate_Cost(dest2_Cost);
		return("함께가는 사람들의 도착지 : " + dest1 + " " + dest2 + "\n" + "혼자갈때의 예상 요금 : " + to_string(alone) + "\n" + "함께갈때의 예상 요금 : " + to_string((int)(totalCost * percent)));
	case 4: 
		dest1 = _event->getPassenger(0)->getDestAddr();
		dest2 = _event->getPassenger(1)->getDestAddr();
		dest3 = _event->getPassenger(2)->getDestAddr();
		dest1_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest1));
		dest2_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest2));
		dest3_Cost = calculate_Length(_graph, _graph->convertEdge(start), _graph->convertEdge(dest3));
		with = alone + calculate_Cost(dest1_Cost) + calculate_Cost(dest2_Cost) + calculate_Cost(dest3_Cost);
		return("함께가는 사람들의 도착지 : " + dest1 + " " + dest2 + " " + dest3 + "\n" + "혼자갈때의 예상 요금 : " + to_string(alone) + "\n" + "함께갈때의 예상 요금 : " + to_string((int)(totalCost * percent)));
	default:
		return NULL;
	}
}


int Calculation::calculate_Personal_Cost(int total, double percent) {	//개인별 내야할 돈을 계산해준다.
	double returnValue = total * percent;	//총액 x 비율로 돈계산
	returnValue = floor(returnValue+0.5);	//반올림해서 저장한다.
	return (int)returnValue;	//어차피 반올림으로인해 정수가 되었으니 형변환해서 반환한다.
}

double Calculation::calculate_percent(int total, int mine) {			//돈을 내야할 비율 계산
	return  mine/ ((double)total);
}

int Calculation::calculate_totalLength(int n, Event* _event, Graph* _graph) {


	if (n == 2) {
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1));
	}
	else if (n == 3) {
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1)) +
			_graph->originalLength(_event->getPassenger(2));
	}
	else if (n == 4) {
		return _graph->originalLength(_event->getPassenger(0)) + _graph->originalLength(_event->getPassenger(1)) +
			_graph->originalLength(_event->getPassenger(2)) + _graph->originalLength(_event->getPassenger(3));
	}
	return 0;
}