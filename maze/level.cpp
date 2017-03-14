#include "level.h"



#include<iostream>
#include<fstream>
using namespace std;


level::level()
{
	_x = 0;
	_y = 0;
	//l = 0;
	//l = fn;
}

void level::load(int fn) {

	//load the lvl
	ifstream fi;
	 
cout << "level  " << fn << endl;
	string levelString = to_string(fn);
	string filelevel = "level" + levelString + ".txt";
	

	l = fn;
	cout << "level    "<<l<<endl;
	fi.open(filelevel);

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
	for (int i = 0; i < lvl.size(); i++)
	{
		//cout << i << endl;

		for (int j = 0; j < lvl[i].size(); j++) {
			t = lvl[i][j];
			//cout << j << endl;

			switch (t)
			{
			case'@':
			//	cout << j  << endl;
				setposition(j, i );



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
void level::move(int x, int y) {

	int px, py;

	getposition(px, py);
	//cout << "mm" << px << py << endl;
		mt = gett(px+ x, py + y);

		switch (mt) {
		case '#':
			cout << "you ran into a wall" << endl;
			break;
		case'.':
			setposition(px+ x, py + y);


			sett(px, py, '.');
			sett(px+ x, py + y, '@');
			break;
		case'H':
			next();
			cout << l;

			cout << "next";
			system("pause");
			break;

		}
		
}
/*void level::relMove(int dx, int dy)
{
	getposition(x, y);

	int x, y;
	x = _x + dx;
	y = _y + dy;
	move(x, y);
}*/
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
	//cout << "kk" << y;
}
void level::getposition(int& x, int& y) {
	x = _x;
	y = _y;
}
void level::next() {
	lvl.clear();
	
	//if (10>=l) {
		cout<< l <<endl;
		int nxx = l;
		cout << "bhk"<<nxx++<<endl;
		load(nxx);
	//}
	

}
level::~level()
{
}
