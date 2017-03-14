#pragma once
#include <vector>
#include <string>
//#include "player.h"
#include "level.h"



class game
{
private:
	//player _play;

public:
	game(string);
	void lay();
	level Level;
	void move();
};
