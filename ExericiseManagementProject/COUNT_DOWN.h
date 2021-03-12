//#ifndef COUNT_DOWN.H
//#define COUNT_DOWN.H
#pragma once
#include <string>

using namespace std;

class CountDown
{	
	public :

	string name;
	string name1;
	int sec;
	int repeat = 1;
	int total = 0;
	CountDown(string name1, string name, string sec);
	CountDown(string sec);
	void PressEnterKey();
	void CountDownStart();
	void wait();
	void CountDownStart1();
};


//#endif // !COUNT_DOWN.H