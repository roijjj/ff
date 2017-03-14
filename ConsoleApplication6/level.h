#pragma once
#include<vector>
#include<string>
#include<fstream>


using namespace std;

class level
{
public:
	level();
	void load(string);
	void print();
	void move(char input);
	char gett(int, int);
	void sett(int, int, char);
	void setposition(int x, int y);
	void getposition(int& x, int& y);

	~level();
private:
	vector <string> lvl;
	int _x;
	int _y;
	char mt;
};
