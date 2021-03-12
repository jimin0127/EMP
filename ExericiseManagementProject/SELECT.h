#include <string>

using namespace std;

class mainSelect {
public:
	int x = 50;
	int y = 12;
	int keyControl();
	int menuDraw();
	void gotoxy(int x, int y);
};

class exerciseSelect{
public:
	int x = 50;
	int y = 12;
	int keyControl();
	int menuDraw(string user_id);
	void gotoxy(int x, int y);
};


