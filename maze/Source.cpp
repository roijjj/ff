#include <fstream>
#include <iostream>
#include <conio.h>


#include "level.h"
level Level;


void move();
void game(int); 
void play() {
	bool flag = false;
	while (flag != true) {
		Level.print();
		move();


	}

}
int main() {

	
	cout << "1. new game \n" << "2. select a level\n" << "3. exit" << endl;
	int im;
		 cin>>im;
		
		 //
	switch (im) {
	case 1://loads game from th first level
		
		game (1);
	play();
		break;
	case 2://loads game from a spcific level
		int ll;
		cout << "select a level 1-5";
		cin >> ll;
		
		game(ll);
		//play();
		break;
	case 3://exits the game
		return 0;
		break;
	}
		

}
void move() {



	char input;
	input = _getch();

	switch (input) {

	case 'w':
	case 'W':
		Level.move(0, -1);

		break;
	case 's':
	case 'S':
		Level.move(0, 1);

		break;
	case 'a':
	case 'A':
		Level.move(-1, 0);

		break;
	case 'd':
	case 'D':
		Level.move(1, 0);

		break;
	}

}
void game (int lvl) {

	//plaer.init()
	//l=lvl;


	//Level.move(0, -1);

	Level.load(lvl);
	/*bool flag = false;
	while (flag != true) {
	Level.print();
	move();
	}*/

}
