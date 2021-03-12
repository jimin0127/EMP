#pragma once
#include <string>

using namespace std;
class SignIn {

public :
	void loginFiled();
	int x = 40;
	int y = 12;
	void gotoxy(int x, int y);
	void checkLogin(string name, string id, string pw);
};