#pragma once

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <mysql.h>
#include "COUNT_DOWN.h"
#include <string>


using namespace std;

class mysqlConnection
{
	
public :

	sql::Driver* driver;
	sql::Connection* con;
	sql::ResultSet* rs;
	sql::Statement* st;
	string user_id;
	MYSQL Conn;             // MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;  // MySQL �ڵ�
	MYSQL_RES* Result;      // ���������� ����� ��� ����ü ������
	MYSQL_RES* Result1;
	MYSQL_ROW Row;          // ���������� ����� ���� ���� ������ ��� ����ü
	MYSQL_ROW Row1;
	int Stat;               // ������û �� ���(����, ����)
	int stt;
	int stt1;
	int count = 0;
	void connection();
	int insertUser(string name, string id, string pw);
	int signIn(string name, string id, string pw);
	void getList(string user_id);
	int addExercise(string user_id, string name, string eTime, string rTime);
	void getTime(string user_id);

	string getCal(string name);

	void getRanking();

	void addTime(string user_id, int name);
};