#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "DO_EXERCISE.h"
#include "COUNT_DOWN.h"
#include "MYSQL_CONNECTION.h"
#include <string>
#include <boost/lexical_cast.hpp>


using namespace std;

void DoExercise::viewList(string user_id) {
	gotoxy(x - 5, y - 9);
	std::cout << "� ����Ʈ" << endl;
	mysqlConnection mc;
	mc.getList(user_id);

	cout << "�ݺ� Ƚ���� �������ּ���";
	cin >> repeat;


	mc.getTime(user_id);
}

void DoExercise::gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
