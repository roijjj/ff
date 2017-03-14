

#include "game.h"
#include<iostream>
#include <conio.h>

using namespace std;




game::game(string lvl) {

	//plaer.init()
	Level.load(lvl);
	Level.print();
	system("pause");
}



void game::lay() {
	bool flag = false;
	while (flag != true) {
		Level.print();
		move();


	}

}


void game::move() {

	cout << "to move it is w, s, a, d"<<endl;


	char input;
	input = _getch();
	//cout << input << endl;
	Level.move(input);
}