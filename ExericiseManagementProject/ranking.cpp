#include <iostream>
#include "RANKING.h"
#include "MYSQL_CONNECTION.h"
#include <string>

using namespace std;

void Ranking::viewList(string user_id) {
	mysqlConnection mc;
	mc.getRanking();
}