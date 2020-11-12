#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

using namespace std;

constexpr auto UP = 1;
constexpr auto DOWN = 2;
constexpr auto RIGHT = 3;
constexpr auto LEFT = 4;
constexpr auto SPACE = 0;

void LaunchManager();
int Menu();
void gotoxy(int, int);
int keycontrol();
void cursor(int);

void GameManager();
void Stage_1();
void Move(int*,int*,int,int);
void MapDraw_1(int*,int*);
char temp[20][56];
char map_1[20][56] = {
	{"11111111111111111111111111111111111111111111111111"},
	{"10p01000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000zzzzzzzz0000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000g01"},
	{"10000000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111"},
};


//void PlayerInfor();//플레이어 데이터를 가져와서 진행
//void Battle();//몬스터,플레이어 데이터를 가져와서 진행


int main(){

	LaunchManager();
	GameManager();

	return 0;
}

void LaunchManager(){
	system("mode con cols=70 lines=30 | title 제목");//최대범위 가로100 세로30
	cursor(0);
	Menu();
}
void GameManager() {
	system("cls");
	Stage_1();
	//스테이지1~5 실행
}



void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void cursor(int n) {  // 커서 보이기 & 숨기기
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor; //구조체 선언 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; //커서 노출여부 1:보임, 0:안보임 
	ConsoleCursor.dwSize = 1; //커서 사이즈 
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int Menu() {
	//메뉴 출력
	cout << "\n\n\n\n";
	cout << " 제목을 뭘로 하지...\n";

	int x = 30, y = 15;
	gotoxy(x - 2, y);
	cout << "> 게임 시작";
	gotoxy(x, y+1);
	cout << "기록 보기";
	gotoxy(x, y+2);
	cout << "게임 종료";
	gotoxy(x - 20, y + 4);
	cout << "w,s를 통해 상하 이동을 하고, 스페이스바로 선택합니다!!\n";

	//메뉴 선택
	while (1) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SPACE: {
			if (y == 15) return 0;
			//if (y == 16) GameRecord();
			if (y == 17) system("exit");
			break;
		}
		}
	}
}

int keycontrol(){
	char key = _getch();

	if (key == 'w' || key == 'W') {
		return UP;
	}
	else if (key == 's' || key == 'S') {
		return DOWN;
	}
	else if (key == 'a' || key == 'A') {
		return LEFT;
	}
	else if (key == 'd' || key == 'D') {
		return RIGHT;
	}
	else if (key == ' ') {
		return SPACE;
	}
}

/*GameRecord에서 뭔가 이상하다...
//void GameRecord(){
	int n = keycontrol();
	system("cls");
	//게임 기록 불러오기
	cout << "게임 기록을 출력해보자!!\n" << "넘어가려면 스페이스바를 누르세요...\n";
	if (n == SPACE) {
		system("cls");
		Menu();
	}
	
}*/


void Stage_1() {
	int x, y;
	int on = 1;

	gotoxy(0, 21);
	cout << "게임을 시작합니다!\n";
	cout << "P는 플레이어의 현재 위치입니다." << "wsad를 이용해 조작합니다.\n";
	cout << "!는 몬스터가 있는 위치입니다." << "$는 아이템의 위치입니다.\n";
	cout << "목표지점인 G까지 이동하면 스테이지를 클리어합니다!\n";

	MapDraw_1(&x, &y);

	while (on) {
		int n = keycontrol();
		switch (n) {
		case UP:{
			Move(&x, &y, 0, -1);
			break; }
		case DOWN:{
			Move(&x, &y, 0, 1);
			break; }
		case RIGHT:{
			Move(&x, &y, 1, 0);
			break; }
		case LEFT:{
			Move(&x, &y, -1, 0);
			break; }
		case SPACE: 
			on = 0;
		}
	}
}
void MapDraw_1(int* x, int* y) {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 56; j++) {
			if (map_1[i][j] == '0') {
				gotoxy(j, i);
				cout << " ";
			}
			else if (map_1[i][j] == '1') {		//벽면
				gotoxy(j, i);
				cout << "*";
			}
			else if (map_1[i][j] == 'p') {//시작점
				gotoxy(j, i);
				cout << "P";
				*x = j;
				*y = i;
			}
			else if (map_1[i][j] == 'g') {//목표지점
				gotoxy(j, i);
				cout << "G";
			}
			else if (map_1[i][j] == 'm') {//몬스터
				gotoxy(j, i);
				cout << "!";
			}
			else if (map_1[i][j] == 'i') {//아이템
				gotoxy(j, i);
				cout << "$";
			}
		}
	}
}

void Move(int* x, int* y, int px, int py) {

	gotoxy(*x, *y);
	cout << " ";
	gotoxy(*x + px, *y + py);
	cout << "P";

	*x += px;
	*y += py;
}