#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SELECT.h"
#include "SIGN_IN.h"
#include "SIGN_UP.h"
#define UP 0
#define DOWN 1
#define ENTER 2

using namespace std;


int mainSelect::menuDraw() {
	gotoxy(x-5, y - 5);
	cout << "운동관리프로그램";
	gotoxy(x - 2, y);
	cout << ">> 로그인";
	gotoxy(x, y + 1);
	cout << " 회원가입";
	gotoxy(x, y + 2);
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
				if (y < 14) {
					gotoxy(x - 2, y);
					cout << "  ";
					gotoxy(x - 2, ++y);
					cout << ">>";
				}
				break;
			}

			case ENTER: {
				system("cls");
				if (y == 12) {
					SignIn si;
					si.loginFiled();
				}
				if (y == 13) {
					SignUp su;
					su.signupFiled();
				}
				if (y == 14) {
					system("cls");
					exit(0);
				}

				
			}
		}
	}
}

void mainSelect::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int mainSelect::keyControl() {
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
