#pragma once
#include <string>

using namespace std;
class SignUp {
private:
	int x = 40;
	int y = 12;
public:
	void signupFiled();
	void gotoxy(int x, int y);
	void signUpQuery(string name, string id, string pw);
};