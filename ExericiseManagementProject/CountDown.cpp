#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <ctime>
#include <conio.h> //getch 함수 사용
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

	// 현재 시간과 설정한 초를 더하여 끝나는 시간을 구함
	endwait = clock() + 1 * CLOCKS_PER_SEC;
	// 현재시간이 끝나는 시간보다 작으면 반복
	while (clock() < endwait) {	}
	total++;
}

void CountDown::PressEnterKey()
{
	system("cls");
	cout << "\t\t\t\t\t\t[Enter] 키를 누르면 운동을 시작합니다. " << endl;
	int key = _getch(); //입력한 키의 아스키코드를 반환
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
			printf("\t\t\t\t\t\t카운트 다운 \n");
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
			cout << "\t\t\t\t\t\t  " << "휴식시간" << endl;
			printf("\t\t\t\t\t\t카운트 다운 \n");
			printf("\t\t\t\t\t\t    %d \n", n);
			wait();
			system("cls");
		}
	}
}
