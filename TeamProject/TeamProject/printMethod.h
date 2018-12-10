#pragma once
#include <string>
using namespace std;
class printMethod
{
public:
	printMethod();
	~printMethod();
	void logo();
	void first();
	void start(string* start, string* dest);
	void loading();
	void moving();
	int decide();
	void arrive(string cost);
	void find();
	void check(string start, string dest);
	void showlist(string list);
	void buddy(string friends);
	bool restart();
	void notCollectStart(string start);
	void notCollectDest(string dest);
	void noPeople();
};

