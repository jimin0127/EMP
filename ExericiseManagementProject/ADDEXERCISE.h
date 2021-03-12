#pragma once
#include <string>
using namespace std;

class AddExercise {
public:
	string name;
	string eTime;
	string rTime;
	int x = 50;
	int y = 27;
	int menuDraw(string user_id);
	void gotoxy(int x, int y);
	//map<string, string> getName(); 
	int keyControl();
};
