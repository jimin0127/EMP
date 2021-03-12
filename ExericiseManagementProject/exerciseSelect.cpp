#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SELECT.h"
#include "ADDEXERCISE.h"
#include "DO_EXERCISE.h"
#include "RANKING.h"
#include <string>
#define UP 0
#define DOWN 1
#define ENTER 2

using namespace std;


int exerciseSelect::menuDraw(string user_id) {
	gotoxy(x - 5, y - 5);
	cout << "운동관리프로그램";
	gotoxy(x - 2, y);
	cout << ">> 운동하기";
	gotoxy(x, y + 1);
	cout << " 운동추가하기";
	gotoxy(x, y + 2);
	cout << " 칼로리소모량 알아보기";
	gotoxy(x, y + 3);
	cout << " 종료";

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				cout << "  ";
				gotoxy(x - 2, --y);
				cout << ">>";
			}break;
		}

		case DOWN: {
			if (y < 15) {
				gotoxy(x - 2, y);
				cout << "  ";
				gotoxy(x - 2, ++y);
				cout << ">>";
			}
			break;
		}

		case ENTER: {
			if (y == 12) {
				system("cls");
				DoExercise de;
				de.viewList(user_id);
			}
			if (y == 13) {
				system("cls");
				AddExercise ae;
				ae.menuDraw(user_id);
			}
			if (y == 14) {
				system("cls");
				Ranking rk;
				rk.viewList(user_id);
			}
			if (y == 15) {
				system("cls");
				exit(0);
			}
		}
		}
	}
}

void exerciseSelect::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int exerciseSelect::keyControl() {
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
