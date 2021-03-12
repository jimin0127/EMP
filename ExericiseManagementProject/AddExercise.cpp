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
	cout << "*******� �߰�********" << endl;
	gotoxy(x - 25, y - 22);
	cout << "1. � ��� �Ͻðڽ��ϱ�?(��ȣ�� �Է����ּ���)" << endl;
	gotoxy(x - 15, y - 21);
	cout << "<<<<Į�θ� �ڵ� ��� � ����Ʈ>>>>" << endl;
	gotoxy(x - 7, y - 20);
	cout << "1. �ȱ������";
	gotoxy(x - 7, y - 19);
	cout << "2. �޸���";
	gotoxy(x - 7, y - 18);
	cout << "3. ������Ÿ��";
	gotoxy(x - 7, y - 17);
	cout << "4. �ٳѱ�";
	gotoxy(x - 7, y - 16);
	cout << "5. ���߱�";
	gotoxy(x - 7, y - 15);
	cout << "6. ��������Ű��";
	gotoxy(x - 13, y - 13);	
	cout << ">> ";
	cin >> name;
	gotoxy(x - 25, y - 12);
	cout << "2. � �ð�(��)�� �������ּ���." << endl;
	gotoxy(x - 13, y - 11);
	cout << ">> ";
	cin >> eTime;
	gotoxy(x - 25, y - 10);
	cout << "3. ���� �ð�(��)�� �������ּ���. " << endl;
	gotoxy(x - 13, y - 9);
	cout << ">> ";
	cin >> rTime;
	gotoxy(x - 25, y - 8);
	cout << "���� �߰� �Ǿ� �ִ� �(����, ��ð�, ���� �ð�)" << endl;


	gotoxy(0, y - 7);
	mysqlConnection mc;
	mc.getList(user_id);

	//map<string, string>::iterator iter;
	//map<string, string> nameMap = getName();

	////���ٹ�� 1 
	//for (iter = nameMap.begin(); iter != nameMap.end(); iter++) {
	//	cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	//}


	gotoxy(x - 3, y);
	cout << ">> �߰��ϱ�";
	gotoxy(x - 1, y + 1);
	cout << " �ڷΰ���";

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

//TODO: mysql connection���� ������ ����

//map<string, string> AddExercise::getName() {
//	//mysql connection���� �������� 
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