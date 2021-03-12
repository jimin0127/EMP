#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include <string>
#include <boost/lexical_cast.hpp>

#include "MYSQL_CONNECTION.h"
#include "SELECT.h"
#include "COUNT_DOWN.h"
#pragma comment(lib, "libmySQL.lib")





using namespace std;

void mysqlConnection::connection()
{
	mysql_init(&Conn);      // MySQL 정보 초기화
	//driver = get_driver_instance();
	//con = driver->connect("localhost:3306", "root", "1234");
	//
	//con->setSchema("cpp_project");
	//if (con != NULL) {
	//	cout << "연결";
	//}

    // 데이터베이스와 연결
    ConnPtr = mysql_real_connect(&Conn, "localhost", "root", "1234", "cpp_project", 3306, NULL, 0);
	
    if (ConnPtr == NULL) // 연결 결과 확인. NULL일 경우 연결 실패한것.
    {
        cout << "error : " << mysql_error(&Conn);
    }
    else {
    }

}

int mysqlConnection::insertUser(string name, string id, string pw) {
	try {
		connection();
		string SQL = "INSERT INTO user(user_name, user_id, user_pw) VALUES ('" + name + "', '" + id + "', '" + pw + "');";

		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}

		return EXIT_SUCCESS;
	}
	catch (sql::SQLException &e) {
		cout << e.getErrorCode();
		return EXIT_FAILURE;
	}

}


int mysqlConnection::signIn(string name, string id, string pw) {
	try {
		connection();
		string SQL = "SELECT * FROM USER WHERE user_id = '" + id + "'";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {
			Result = mysql_store_result(ConnPtr);

			while ((Row = mysql_fetch_row(Result)) != NULL) {

				if (Row[1] == name && Row[2] == id && Row[3] == pw) {
					user_id = Row[0];
					system("cls");
					exerciseSelect es;
					es.menuDraw(user_id);
					
				}
				else {
					mainSelect ms;
					ms.menuDraw();
					cout << "로그인 실패";
				}
			}
			mysql_free_result(Result);
		}

		return EXIT_SUCCESS;
	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
		return EXIT_FAILURE;
	}

}

int mysqlConnection::addExercise(string user_id, string name, string eTime, string rTime) {
	try {
		connection();
		string SQL = "INSERT INTO exercise(ex_name, ex_eTime, ex_rTime, user) VALUES ('" + name + "', '" + eTime + "', '" + rTime + "', '" + user_id + "');";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		exerciseSelect es;
		es.menuDraw(user_id);

		return EXIT_SUCCESS;
	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
		return EXIT_FAILURE;
	}
	
	return 0;
}
void mysqlConnection::getList(string user_id) {
	try {
		connection();
		string SQL = "select * from exercise b join user a on a.id = b.user";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {
			Result = mysql_store_result(ConnPtr);
			int num = 1;
			while ((Row = mysql_fetch_row(Result)) != NULL) {
				if (Row[6] == user_id) {
					string name;

					string SQL = "select * from exercisecal where id = " + string(Row[1]) + ";";
					stt1 = mysql_query(ConnPtr, SQL.c_str());
					if (stt1 != 0) {
						cout << stderr << "error : " << mysql_error(&Conn);
					}
					else {

						Result1 = mysql_store_result(ConnPtr);
						while ((Row1 = mysql_fetch_row(Result1)) != NULL) {
							name = Row1[1];
						}
					}

					/*if (string(Row[1]).compare("1") == 0) {
						name = "팔굽혀펴기";
					}
					else if (string(Row[1]).compare("2") == 0) {
						name = "달리기";
					}
					else if (string(Row[1]).compare("3") == 0) {
						name = "자전거타기";
					}
					else if (string(Row[1]).compare("4") == 0) {
						name = "줄넘기";
					}
					else if (string(Row[1]).compare("5") == 0) {
						name = "춤추기";
					}
					else if (string(Row[1]).compare("6") == 0) {
						name = "윗몸일으키기";
					}*/
					cout <<num++ << ". " << name << "  ";
					cout << Row[2] << "  ";
					//eTime[count] = boost::lexical_cast<int>(Row[2]);

					cout << Row[3] << endl;
					//rTime[count] = boost::lexical_cast<int>(Row[3]);
				}
			}

			mysql_free_result(Result);
		}

	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
	}
}

void mysqlConnection::getTime(string user_id) {
	try {
		//int rp = boost::lexical_cast<int>(repeat);
		connection();
		string SQL = "select * from exercise b join user a on a.id = b.user";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {

			Result = mysql_store_result(ConnPtr);
			string name;
			while ((Row = mysql_fetch_row(Result)) != NULL) {
				for (int i = 0; i < 2; i++) {
					if (Row[6] == user_id) {
						//system("cls");

						if (string(Row[1]).compare("1") == 0) {
							name = "팔굽혀펴기";
						}
						else if (string(Row[1]).compare("2") == 0) {
							name = "달리기";
						}
						else if (string(Row[1]).compare("3") == 0) {
							name = "자전거타기";
						}
						else if (string(Row[1]).compare("4") == 0) {
							name = "줄넘기";
						}
						else if (string(Row[1]).compare("5") == 0) {
							name = "춤추기";
						}
						else if (string(Row[1]).compare("6") == 0) {
							name = "윗몸일으키기";
						}
						CountDown cd(Row[1], name, Row[2]);

						CountDown co(Row[3]);
					}
				}
			}
			exerciseSelect es;
			es.menuDraw(user_id);

			mysql_free_result(Result);
		}

	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
	}

}

string mysqlConnection::getCal(string name) {
	try {
		connection();
		string SQL = "select * from exercise where id = '" + name + "';";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {

			Result = mysql_store_result(ConnPtr);
			string cal;

			while ((Row = mysql_fetch_row(Result)) != NULL) {
				if (Row[1] == name) {
					cal = string(Row[2]);
				}
			}

			return cal;

			mysql_free_result(Result);
		}

	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
	}

}

void mysqlConnection::addTime(string user_id, int time) {
	try {
		connection();
		string SQL = "select * from exercise where id = '" + user_id + "';";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {

			Result = mysql_store_result(ConnPtr);
			int time;

			//while ((Row = mysql_fetch_row(Result)) != NULL) {
			//	time = string(Row[2]);
			//	
			//}


			mysql_free_result(Result);
		}

	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
	}

}



void mysqlConnection::getRanking() {
	try {
		connection();
		int count = 1;
		string SQL = "select * from user order by total_time desc;";
		stt = mysql_query(ConnPtr, SQL.c_str()); //stt가 0이 아니면 에러 
		if (stt != 0)
		{
			cout << stderr << "error : " << mysql_error(&Conn);
		}
		else {
			Result = mysql_store_result(ConnPtr);
			cout << "\t\t\t\t" << "순위" << "\t\t이름" << "\t\t" << "시간" << endl;

			while ((Row = mysql_fetch_row(Result)) != NULL) {
				cout <<  "\t\t\t\t" << count <<"\t\t" << Row[1] << "\t\t";
				cout << Row[4] << endl;
				count++;
			}

			mysql_free_result(Result);
		}
		
	}
	catch (sql::SQLException& e) {
		cout << e.getErrorCode();
	}
}




//리스트 가져오기 추가하기, 운동하기
