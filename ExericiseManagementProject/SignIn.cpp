#include <iostream>
#include <Windows.h>
#include <string>
#include "SIGN_IN.h"
#include "MYSQL_CONNECTION.h"

using namespace std;

void SignIn::loginFiled() {

	string name;
	string id;
	string pw;
	gotoxy(x, y);
	cout << "�̸� : ";
	cin >> name;
	gotoxy(x, y + 1);
	cout << "���̵� : ";
	cin >> id;
	gotoxy(x, y + 2);
	cout << "��й�ȣ : ";
	cin >> pw;


	mysqlConnection mc;
	mc.signIn(name, id, pw);
}


void SignIn::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}