#ifndef HANDLER_H
#define HANDLER_H

#include "Graph.h"
#include "Calculation.h"
#include "Event.h"

class Handler {

	Calculation* _calculation;
	Graph * _graph;


public:


	Handler(Event* _event, string graphAddr); //持失切

	~Handler(void);			//社瑚切

	void allocCost(Event* _event);

};

#endif







