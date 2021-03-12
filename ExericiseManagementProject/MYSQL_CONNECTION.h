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
	MYSQL Conn;             // MySQL 정보를 담을 구조체
	MYSQL* ConnPtr = NULL;  // MySQL 핸들
	MYSQL_RES* Result;      // 쿼리성공시 결과를 담는 구조체 포인터
	MYSQL_RES* Result1;
	MYSQL_ROW Row;          // 쿼리성공시 결과로 나온 행의 정보를 담는 구조체
	MYSQL_ROW Row1;
	int Stat;               // 쿼리요청 후 결과(성공, 실패)
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