#pragma once
#include <string>
#include <iostream>
#include "MYSQL_CONNECTION.h"
#pragma comment(lib, "libmySQL.lib")
#include <mysql.h>



using namespace std;

class DoExercise : mysqlConnection{
public:
	string repeat;


	int x = 50;
	int y = 12;
	string eTime[5];
	void gotoxy(int x, int y);
	void viewList(string user_id);

};