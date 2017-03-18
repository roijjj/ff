#include "level.h"

#include<iostream>
#include<fstream>
using namespace std;


level::level()
{
	
	_x = 0;
	_y = 0;
	
}

void level::load(int fn) {

	//load the lvl
	ifstream fi;
	 
	string levelString = to_string(fn);//change a int to a string 
	string filelevel = "levels\\level" + levelString + ".txt";
	

	l = fn;
	cout << "level    "<<l<<endl;
	fi.open(filelevel);//opens the file
	
	//checks of the file is there
	if (fi.fail()) {
		cout << "did not open";
		system("pause");

	}
	string line;

	//reads the file into an vector
	while (getline(fi, line)) {
		lvl.push_back(line);

	}
	fi.close();//closes the file

	char t;
	//searchs the vector for the @ symbol 
	for (int i = 0; i < lvl.size(); i++)
	{
		for (int j = 0; j < lvl[i].size(); j++) {
			t = lvl[i][j];

			switch (t)
			{
			case'@':
				setposition(j, i );//sets the position of the player
				break;

			}
		}
	}
}

//prints the vector
void level::print() {

	//cout << string(100, '\n');
cout << "to move it is w, s, a, d" << endl;
	for (int i = 0; i < lvl.size(); i++) {
		

		cout << lvl[i] << endl;

	}
	
}
//moves the player
void level::move(int x, int y) {

	int px, py;

	//gets the posiont of the player
	getposition(px, py);
	
	//gets the postion of where the player want to move
	mt = gett(px+ x, py + y);

		//checks if the player can move to the position 
		switch (mt) {
		case '#':
			cout << "you ran into a wall" << endl;
			break;
		case'.':

			//sets the new postion of the character
			setposition(px+ x, py + y);

			
			sett(px, py, '.');
			sett(px+ x, py + y, '@');
			break;
		case'H':
			
			//calls the next level
			next();
	
		
			break;
			
		}
		
}

//moves onto the next level
void level::next() {
	//clears the vector
	lvl.clear();
	//checks to see if you beat the game
	if (4>=l) {

		
		int nxx ;
		//loads the next level
		nxx =l+1;
		cout << nxx << endl;

		load(nxx);
	}
	else
	{
		cout << "congrats you beat the game" << endl;
		
	}
	

}
