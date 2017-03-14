#pragma once
#include <map>
#include<vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class level
{
public:
	level();
	~level();
	
	void load(int);
	void print();
	void move(int, int );
	char gett(int, int);
	void sett(int, int, char);
	void setposition(int x, int y);
	void getposition(int& x, int& y);
	void next();
	//void relMove(int dx, int dy);


private:
	vector <string> lvl;
	int _x;
	int _y;
	char mt;
	int l;
};


