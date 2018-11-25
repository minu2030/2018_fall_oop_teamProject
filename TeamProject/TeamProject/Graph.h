#ifndef GRAPH_H
#define GRAPH_H

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

	void ViewNeighbors()const;	

	void ViewNeighbor(int vt)const;

	Neighbors FindNeighbors(int vt);	

	int convertEdge(string loc) {
		
		if (loc == "기숙사") return 0;
		else if (loc == "월평역") return 1;
		else if (loc == "유성온천역") return 2;
		else if (loc == "대전역") return 3;
		else if (loc == "카이스트") return 4;
		
	}

};


#endif // !GRAPH_H
