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
				cout << j + 1 << endl;
				setposition(i, j + 1);



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
void level::move(int in) {

	int px, py;

	getposition(px, py);
	cout << "mm" << px << py << endl;
		mt = gett(px, py + in);

		switch (mt) {
		case '#':
			cout << "you ran into a wall" << endl;
			break;
		case'.':
			setposition(px, py + in);


			sett(px, py, '.');
			sett(px, py + in, '@');
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
	_x = x;
	_y = y;
	cout << "kk" << y;
}
void level::getposition(int& x, int& y) {
	x = _x;
	y = _y;
}
level::~level()
{
}