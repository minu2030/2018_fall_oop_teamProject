#include "Graph.h"
#include <string.h>
#include "Passenger.h"


Graph::Graph(int vn) :vn(vn)

{
	matrix = new int *[vn];//매트릭스 메모리 할당

	for (int i = 0; i < vn; i++)

	{
		matrix[i] = new int[vn];//매트릭스 [i-row] 메모리 할당

		memset(matrix[i], 0, sizeof(int)*vn);//메모리 0으로 초기화

	}

}



Graph::~Graph(void)

{

	for (int i = 0; i < vn; i++)

	{

		delete[] matrix[i];//매트릭스 [i-row]  메모리 소멸

	}

	delete[] matrix;//매트릭스 메모리 해제     

}

Graph* Graph::makeGraph(string addr) {


	try {
		fstream inFile;
		inFile.open(addr);	//파일 입력

		string _size;

		string _v1;
		string _v2;
		string _dist;
		string _trash;
		getline(inFile, _size, ',');	//size 입력

		int size = atoi(_size.c_str());
		if (typeid(size).name() != typeid(int).name()) throw(0);
		Graph* _graph = new Graph(size);
		//Graph* _graph = new Graph(atoi(_size.c_str()));	//사이즈만큼 그래프 생성


		while (!inFile.eof()) {


			getline(inFile, _trash, '\n');

			getline(inFile, _v1, ',');
			if (typeid(_v1).name() != typeid(string).name()) throw(1);

			getline(inFile, _v2, ',');
			if (typeid(_v2).name() != typeid(string).name()) throw(1);

			getline(inFile, _dist, ',');
			if (typeid(_dist).name() != typeid(string).name()) throw(1);

			_graph->AddEdge(_v1, _v2, atoi(_dist.c_str()));


		}
		return _graph;
	}

	catch (int error) {
		if (error == 0) printf("사이즈 입력이 올바르지 않습니다.\n");
		else if (error == 1) printf("그래프 정점 형식이 올바르지 않습니다.\n");
	}
}

/*
int Graph::findMinWay(int start, Passenger* ps , Passenger* ps1) {
	int arr[2];
	int dest1 = convertEdge(ps->getDestAddr());
	int dest2 = convertEdge(ps1->getDestAddr());

	arr[0] = matrix[start][dest1] + matrix[dest1][dest2];
	arr[1] = matrix[start][dest2] + matrix[dest2][dest1];

}
*/


int Graph::findMinWay(int start, int dest1, int dest2) {
	int arr[2];
	arr[0] = matrix[start][dest1] + matrix[dest1][dest2];
	arr[1] = matrix[start][dest2] + matrix[dest2][dest1];

	int index = findMin(arr, sizeof(arr) / sizeof(int));

	printf("최소 거리 : %d \n", arr[index]);
	return index;
}



int Graph::findMinWay(int start, int dest1, int dest2, int dest3) {
	int arr[6];
	arr[0] = matrix[start][dest1] + matrix[dest1][dest2] + matrix[dest2][dest3];
	arr[1] = matrix[start][dest1] + matrix[dest1][dest3] + matrix[dest3][dest2];
	arr[2] = matrix[start][dest2] + matrix[dest2][dest3] + matrix[dest3][dest1];
	arr[3] = matrix[start][dest2] + matrix[dest2][dest1] + matrix[dest1][dest3];
	arr[4] = matrix[start][dest3] + matrix[dest3][dest1] + matrix[dest1][dest2];
	arr[5] = matrix[start][dest3] + matrix[dest3][dest2] + matrix[dest2][dest1];


	int index = findMin(arr, sizeof(arr) / sizeof(int));

	printf("최소 거리 : %d \n", arr[index]);
	return index;
}

int Graph::findMinWay(int start, int dest1, int dest2, int dest3, int dest4) {
	int arr[24];
	arr[0] = matrix[start][dest1] + matrix[dest1][dest2] + matrix[dest2][dest3] + matrix[dest3][dest4];//1234
	arr[1] = matrix[start][dest1] + matrix[dest1][dest2] + matrix[dest2][dest4] + matrix[dest4][dest3];//1243
	arr[2] = matrix[start][dest1] + matrix[dest1][dest3] + matrix[dest3][dest2] + matrix[dest2][dest4];//1324
	arr[3] = matrix[start][dest1] + matrix[dest1][dest3] + matrix[dest3][dest4] + matrix[dest4][dest2];//1342
	arr[4] = matrix[start][dest1] + matrix[dest1][dest4] + matrix[dest4][dest2] + matrix[dest2][dest3];	//1423
	arr[5] = matrix[start][dest1] + matrix[dest1][dest4] + matrix[dest4][dest3] + matrix[dest3][dest3];	//1432
																										//---여기까지 1먼저
	arr[6] = matrix[start][dest2] + matrix[dest2][dest1] + matrix[dest1][dest3] + matrix[dest3][dest4];	//2134
	arr[7] = matrix[start][dest2] + matrix[dest2][dest1] + matrix[dest1][dest4] + matrix[dest4][dest3];	//2143
	arr[8] = matrix[start][dest2] + matrix[dest2][dest3] + matrix[dest3][dest1] + matrix[dest1][dest4];	//2314
	arr[9] = matrix[start][dest2] + matrix[dest2][dest3] + matrix[dest3][dest4] + matrix[dest4][dest1];	//2341
	arr[10] = matrix[start][dest2] + matrix[dest2][dest4] + matrix[dest4][dest1] + matrix[dest1][dest3];	//2413
	arr[11] = matrix[start][dest2] + matrix[dest2][dest4] + matrix[dest4][dest3] + matrix[dest3][dest1];	//2431
																											//---여기까지 2먼저
	arr[12] = matrix[start][dest3] + matrix[dest3][dest1] + matrix[dest1][dest2] + matrix[dest2][dest4];	//3124
	arr[13] = matrix[start][dest3] + matrix[dest3][dest1] + matrix[dest1][dest4] + matrix[dest4][dest2];	//3142
	arr[14] = matrix[start][dest3] + matrix[dest3][dest2] + matrix[dest2][dest1] + matrix[dest1][dest4];	//3214
	arr[15] = matrix[start][dest3] + matrix[dest3][dest2] + matrix[dest2][dest4] + matrix[dest4][dest1];	//3241
	arr[16] = matrix[start][dest3] + matrix[dest3][dest4] + matrix[dest4][dest1] + matrix[dest1][dest2];	//3412
	arr[17] = matrix[start][dest3] + matrix[dest3][dest4] + matrix[dest4][dest2] + matrix[dest2][dest1];	//3421
																											//---여기까지 3먼저
	arr[18] = matrix[start][dest4] + matrix[dest4][dest1] + matrix[dest1][dest2] + matrix[dest2][dest3];	//4123
	arr[19] = matrix[start][dest4] + matrix[dest4][dest1] + matrix[dest1][dest3] + matrix[dest3][dest2];	//4132
	arr[20] = matrix[start][dest4] + matrix[dest4][dest2] + matrix[dest2][dest1] + matrix[dest1][dest3];	//4213
	arr[21] = matrix[start][dest4] + matrix[dest4][dest2] + matrix[dest2][dest3] + matrix[dest3][dest1];	//4231
	arr[22] = matrix[start][dest4] + matrix[dest4][dest3] + matrix[dest3][dest1] + matrix[dest1][dest2];	//4312
	arr[23] = matrix[start][dest4] + matrix[dest4][dest3] + matrix[dest3][dest2] + matrix[dest2][dest1];	//4321
																											//---여기까지 4 먼저
	int index = findMin(arr, sizeof(arr) / sizeof(int));

	printf("최소 거리 : %d \n", arr[index]);

	return index;
}


void Graph::AddEdge(string start, string goal, int dist)//간선 추가

{

	matrix[convertEdge(start)][convertEdge(goal)] = dist;//간선 설정

	matrix[convertEdge(goal)][convertEdge(start)] = dist;//간선 설정


}

void Graph::ViewNeighbors()const

{

	cout << "=== 이웃 정점 ===" << endl;

	for (int i = 0; i < vn; i++)

	{

		cout << i << "의 이웃: ";

		ViewNeighbor(i);//i정점의 이웃 보여주기

	}

	cout << endl;

}

void Graph::ViewNeighbor(int vt)const

{

	for (int i = 0; i < vn; i++)

	{
		cout << matrix[vt][i] << " ";
	}

	cout << endl;

}

Neighbors Graph::FindNeighbors(int vt)

{

	Neighbors neighbors;

	for (int i = 0; i < vn; i++)

	{

		if (matrix[vt][i])

		{
			neighbors.push_back(i);

		}

	}

	return neighbors;

}