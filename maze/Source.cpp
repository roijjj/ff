#include <fstream>
#include <iostream>
#include <conio.h>


#include "level.h"
level Level;

void game (int lvl) {

	//plaer.init()
	//l=lvl;

	
		//Level.move(0, -1);

	Level.load(lvl);
	Level.print();

	system("pause");
}
void move () {

	cout << "to move it is w, s, a, d" << endl;


	char input;
	input = _getch();
	//cout << input << endl;
	//Level.move(input);
	switch (input) {

	case 'w':
	case 'W':
		Level.move(0,-1);

		break;
	case 's':
	case 'S':
		Level.move(0,1);

		break;
	case 'a':
	case 'A':
		Level.move(-1,0);

		break;
	case 'd':
	case 'D':
		Level.move(1,0);

		break;
	}

}
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

	switch (im) {
	case 1:
		game (1);
	play();
		break;
	case 2:
		int ll;
		cout << "select a level 1-10";
		cin >> ll;
		cout << ll << endl;
		system("pause");
		game(ll);
		play();
		break;
	case 3:
		break;
	}
		
}
