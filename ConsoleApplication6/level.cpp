#include "level.h"



#include<iostream>
#include<fstream>
using namespace std;


level::level()
{
	_x = 0;
	_y = 0;
	
}

void level::load(string fn) {

	//load the lvl
	ifstream fi;

	fi.open(fn);
	if (fi.fail()) {
		cout << "did not open";
		system("pause");

	}
	string line;

	while (getline(fi, line)) {
		lvl.push_back(line);

	}
	fi.close();

	char t;
	for (int i = 0; i < lvl.size(); i++) {
		for (int j = 0; j < lvl[i].size(); j++) {
			t = lvl[i][j];

			switch (t)
			{
			case'@':
				cout << i << endl;
				setposition(i, j);
				
				

				break;

			}
		}
	}
}
void level::print() {
	for (int i = 0; i < lvl.size(); i++) {
		cout << lvl[i] << endl;

	}
	cout << endl;
}
void level::move(char input) {

	int px, py;
	
	getposition(px, py);
	cout <<"mm"<< px <<py<< endl;


	switch (input) {

	case 'w':
	case 'W':
		mt = gett(px, py-1);
		
		
		switch (mt) {
		case '#':
			cout << "you ran into a wall" << endl;
			break;
		case'.':
			setposition(px, py - 1);


			sett(px, py, '.');
			sett(px, py - 1, '@');
			break;
			
		}
			break;
		case 's':
		case 'S':
			mt = gett(px, py + 1);

			switch (mt) {
			case '#':
				cout << "you ran into a wall"<<endl;
				break;
			case'.':
				setposition(px, py+1);


				sett(px, py, '.');
				sett(px, py+1, '@');
				break;

			}

			break;

		case 'a':
		case'A':
			mt = gett(px-1, py);
			switch (mt) {
			case '#':
				cout << "you ran into a wall";
				break;
			case'.':
				setposition(px-1, py);


				sett(px, py, '.');
				sett(px-1, py, '@');
				break;

			}
			break;
		case 'd':
		case 'D':
			mt = gett(px +1, py);
			switch (mt) {
			case '#':
				cout << "you ran into a wall";
				break;
			case'.':
				setposition(px +1, py);


				sett(px, py, '.');
				sett(px +1, py, '@');
				break;
			case' ':
				cout << "your finished";
				system("pause");
				break;

			}
			break;

		default:
			cout << "input invalid" << endl;
			break;
		}
}

char level::gett(int x, int y)
{
	return lvl[y][x];

}
void level::sett(int x, int y, char tile)
{
	lvl[y][x] = tile;


}
void level::setposition(int x, int y) {
	 _x=x ;
	_y=y  ;
	
}
void level::getposition(int& x, int& y) {
	x = _x;
	y = _y;
}
level::~level()
{
}
