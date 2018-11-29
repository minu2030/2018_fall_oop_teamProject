#ifndef GRAPH_H
#define GRAPH_H
#include "Passenger.h"

#include <string>
#include <fstream>

#include <iostream>

#include <vector>

using namespace std;

typedef vector<int> Neighbors;

class Graph

{

	const int vn;//정점의 개수
	int **matrix;//인접 행렬 
	 

public: 

	Graph(int vn);		//Graph 생성자

	~Graph(void);		//Graph 소멸자

	void AddEdge(string start, string goal, int dist);//간선 추가

	int matrixValue(int i, int j);		//그래프값 반환

	int convertEdge(string loc);		//string 목적지 받아서 인덱스로 반환

	Graph* makeGraph(string addr);		//그래프 만들어주는 함수


	int findMinWay(Passenger* p1, Passenger* p2);	
	int findMinWay(Passenger* p1, Passenger* p2, Passenger* p3);
	int findMinWay(Passenger* p1, Passenger* p2, Passenger* p3, Passenger* p4);
	
	int findMin(int arr[], int size);		//최소값을 찾아주는 함수

	int getCost(int len) {
		return 900 * len;
	}
};


#endif // !GRAPH_H


/*
int findMinWay(int start, int dest1, int dest2);	//최소경로 찾아주는 함수
int findMinWay(int start, int dest1, int dest2, int dest3);
int findMinWay(int start, int dest1, int dest2, int dest3, int dest4);
*/
