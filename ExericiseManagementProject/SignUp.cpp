#include "SIGN_UP.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "MYSQL_CONNECTION.h"
#include "SELECT.h"

using namespace std;

void SignUp::signupFiled() {
	string name;
	string id;
	string pw;
	string yn;
	gotoxy(x, y);
	cout << "�̸� : ";
	cin >> name;
	gotoxy(x, y + 1);
	cout << "���̵� : ";
	cin >> id;
	gotoxy(x, y + 2);
	cout << "��й�ȣ : ";
	cin >> pw;


	gotoxy(x, y + 3);
	cout << name << "��, " << "ȸ�������Ͻðڽ��ϱ�? (y / n)";
	gotoxy(x, y + 4);
	cin >> yn;
	if (yn == "y") {
		signUpQuery(name, id, pw);
	}
	else {
		system("cls");
		mainSelect mc;
		mc.menuDraw();
	}
}

void SignUp::signUpQuery(string name, string id, string pw) {
	mysqlConnection mc;
	
	int a = mc.insertUser(name, id, pw);
	if (a == EXIT_SUCCESS) {
		system("cls");
		mainSelect mc;
		mc.menuDraw();

	}
	else {
		cout << "insert ����";
	}
	
	Sleep(1000);
	//system("cls");
}

void SignUp::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}