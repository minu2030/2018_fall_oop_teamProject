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

	int matrixValue(int i, int j) {
		return matrix[i][j];
	}

	int convertEdge(string loc) {

		if (loc == "기숙사") return 0;
		else if (loc == "월평역") return 1;
		else if (loc == "유성온천역") return 2;
		else if (loc == "카이스트") return 3;
		else if (loc == "봉명동") return 4;
		else if (loc == "월드컵경기장") return 5;
		else if (loc == "복합터미널") return 6;
		else if (loc == "은행동") return 7;
		else if (loc == "둔산동") return 8;
		else if (loc == "대전역") return 9;
	}

	Graph* makeGraph(string addr);

	//int Graph::findMinWay(int start, Passenger* ps, Passenger* ps1);

	int findMinWay(int start, int dest1, int dest2);

	int findMinWay(int start, int dest1, int dest2, int dest3);

	int findMinWay(int start, int dest1, int dest2, int dest3, int dest4);


	


	int findMin(int arr[], int size) {
		int min = arr[0];
		for (int i = 0; i < size; i++) {
			if (min > arr[i]) min = arr[i];
		}	//최소거리 찾고

		for (int i = 0; i < size; i++) {
			if (arr[i] == min) return i;	//그 인덱스 반환
		}
		return 0;
	}

};


#endif // !GRAPH_H
