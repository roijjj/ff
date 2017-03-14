#include <map>
#include <fstream>
#include <iostream>
#include <conio.h>


#include "level.h"
level Level;

void game (string lvl) {

	//plaer.init()
	Level.load(lvl);
	Level.print();
	system("pause");
}
void move () {

	cout << "to move it is w, s, a, d" << endl;


	char input;
	input = _getch();
	//cout << input << endl;
	Level.move(input);
	switch (input) {

	case 'w':
	case 'W':
		Level.move(-1);

		break;
	case 's':
	case 'S':
		Level.move(1);

		break;
	case 'a':
	case 'A':
		Level.move(-1);

		break;
	case 'd':
	case 'D':
		Level.move(1);

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

	game ("maze1.txt");

		play();
}