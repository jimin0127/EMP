#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <ctime>
#include <conio.h> //getch �Լ� ���
#include "COUNT_DOWN.h"
#include <string>
#include "MYSQL_CONNECTION.h"

using namespace std;

CountDown::CountDown(string name1, string name, string sec)
{	
	this->sec = stoi(sec);
	this->total = 0;
	this->name = name;
	this->name1 = name1;

	PressEnterKey();
}
CountDown::CountDown(string sec)
{
	system("cls");
	
	this->sec = stoi(sec);

	CountDownStart1();
}
void CountDown::wait() {

	clock_t endwait;

	// ���� �ð��� ������ �ʸ� ���Ͽ� ������ �ð��� ����
	endwait = clock() + 1 * CLOCKS_PER_SEC;
	// ����ð��� ������ �ð����� ������ �ݺ�
	while (clock() < endwait) {	}
	total++;
}

void CountDown::PressEnterKey()
{
	system("cls");
	cout << "\t\t\t\t\t\t[Enter] Ű�� ������ ��� �����մϴ�. " << endl;
	int key = _getch(); //�Է��� Ű�� �ƽ�Ű�ڵ带 ��ȯ
	if (key == 13) {
		CountDownStart();
	}
	else {
		exit(0);
	}

}
void CountDown::CountDownStart() {
	for (int i = 0; i < this->repeat; i++) {
		for (int n = this->sec; n > 0; --n) {
			cout << "\t\t\t\t\t\t  " << name << endl;
			printf("\t\t\t\t\t\tī��Ʈ �ٿ� \n");
			printf("\t\t\t\t\t\t    %d \n", n);
			wait();
			system("cls");
		}
	}
	
	mysqlConnection mc;
	//mc.addTime(user_id, total);
	//cout << this->total << endl;
}

void CountDown::CountDownStart1() {
	for (int i = 0; i < this->repeat; i++) {
		for (int n = this->sec; n > 0; --n) {
			cout << "\t\t\t\t\t\t  " << "�޽Ľð�" << endl;
			printf("\t\t\t\t\t\tī��Ʈ �ٿ� \n");
			printf("\t\t\t\t\t\t    %d \n", n);
			wait();
			system("cls");
		}
	}
}
