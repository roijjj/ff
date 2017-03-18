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
	
	
	void load(int);//loads the level
	void print();//prints the level
	void move(int, int );//moves the player
	void next();//moves to the next leve

	//gets posiont of x and y
	char gett(int x, int y)
	{
		return lvl[y][x];

	}
	//sets ths postition on x and y
	void sett(int x, int y, char tile)
	{
		lvl[y][x] = tile;

	}
	//sets the position the player
	void setposition(int x, int y) {
		_x = x;
		_y = y;
	}
	//gets the position of the player
	void getposition(int& x, int& y) {
		x = _x;
		y = _y;
	}
	
private:
	vector <string> lvl;//the level 
	
	int _x;
	int _y;
	
	char mt;
	int l;
};



