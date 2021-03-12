#include <iostream>
#include "COUNT_DOWN.h"
#include "SELECT.h"
#include "SIGN_IN.h"
#include "SIGN_UP.h"
#include "MYSQL_CONNECTION.h"
#include "ADDEXERCISE.h"
#include "DO_EXERCISE.h"

int main() {
	system("mode con cols=110 lines=35");

	mainSelect ms;

	ms.menuDraw();



	//exerciseSelect es;
	//es.menuDraw();

	//AddExercise ae;
	//ae.menuDraw();

	//DoExercise de;
	//de.viewList();

}