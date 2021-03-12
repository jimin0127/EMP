#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <map>
#include "MYSQL_CONNECTION.h"
#include "ADDEXERCISE.h"
#include "SELECT.h"
#define UP 0
#define DOWN 1
#define ENTER 2


using namespace std;

int AddExercise::menuDraw(string user_id) {
	gotoxy(x - 5, y - 24);
	cout << "*******운동 추가********" << endl;
	gotoxy(x - 25, y - 22);
	cout << "1. 어떤 운동을 하시겠습니까?(번호를 입력해주세요)" << endl;
	gotoxy(x - 15, y - 21);
	cout << "<<<<칼로리 자동 계산 운동 리스트>>>>" << endl;
	gotoxy(x - 7, y - 20);
	cout << "1. 팔굽혀펴기";
	gotoxy(x - 7, y - 19);
	cout << "2. 달리기";
	gotoxy(x - 7, y - 18);
	cout << "3. 자전거타기";
	gotoxy(x - 7, y - 17);
	cout << "4. 줄넘기";
	gotoxy(x - 7, y - 16);
	cout << "5. 춤추기";
	gotoxy(x - 7, y - 15);
	cout << "6. 윗몸일으키기";
	gotoxy(x - 13, y - 13);	
	cout << ">> ";
	cin >> name;
	gotoxy(x - 25, y - 12);
	cout << "2. 운동 시간(초)을 설정해주세요." << endl;
	gotoxy(x - 13, y - 11);
	cout << ">> ";
	cin >> eTime;
	gotoxy(x - 25, y - 10);
	cout << "3. 쉬는 시간(초)을 설정해주세요. " << endl;
	gotoxy(x - 13, y - 9);
	cout << ">> ";
	cin >> rTime;
	gotoxy(x - 25, y - 8);
	cout << "현재 추가 되어 있는 운동(종목, 운동시간, 쉬는 시간)" << endl;


	gotoxy(0, y - 7);
	mysqlConnection mc;
	mc.getList(user_id);

	//map<string, string>::iterator iter;
	//map<string, string> nameMap = getName();

	////접근방법 1 
	//for (iter = nameMap.begin(); iter != nameMap.end(); iter++) {
	//	cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	//}


	gotoxy(x - 3, y);
	cout << ">> 추가하기";
	gotoxy(x - 1, y + 1);
	cout << " 뒤로가기";

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {

			if (y > 27) {
				gotoxy(x - 3, y);
				cout << "  ";
				gotoxy(x - 3, --y);
				cout << ">>";
			}break;
		}

		case DOWN: {
			if (y < 28) {
				gotoxy(x - 3, y);
				cout << "  ";
				gotoxy(x - 3, ++y);
				cout << ">>";
			}
			break;
		}

		case ENTER: {
			system("cls");
			if (y == 27) {
				system("cls");
				mysqlConnection mc;
				mc.addExercise(user_id, name, eTime, rTime);
			}
			if (y == 28) {
				exerciseSelect es;
				es.menuDraw(user_id);
			}
		}
		}
	}


	return 0;
}

//TODO: mysql connection에서 데이터 삽입

//map<string, string> AddExercise::getName() {
//	//mysql connection에서 가져오기 
//	map<string, string> mapName;
//
//	mapName.insert(pair<string, string>("name", "me"));
//	mapName.insert(pair<string, string>("name", "make"));
//
//
//	return mapName;
//}
////map<string, string> getETiem() {
////	//db
////	return;
////}
////map<string, string> getRTime() {
////	//db
////	return;
////}

void AddExercise::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int AddExercise::keyControl() {
	int keyCode = _getch();

	if (keyCode == 72) {
		return UP;
	}
	else if (keyCode == 80) {
		return DOWN;
	}
	else if (keyCode == 13) {
		return ENTER;
	}
}