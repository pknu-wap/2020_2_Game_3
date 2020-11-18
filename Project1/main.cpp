#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

#include "CMap.h"
#include "CMonster.h"
#include "CSystem.h"

using namespace std;

constexpr auto UP = 1;
constexpr auto DOWN = 2;
constexpr auto RIGHT = 3;
constexpr auto LEFT = 4;
constexpr auto SPACE = 0;

class Monster {
public:
	int HP;
	int AP;
	int Xpos;
	int Ypos;
	void Move(int* mx, int* my, int* x, int* y);
};

void LaunchManager();
int Menu();
int keycontrol();

void GameManager();
void Stage_1();
void Move(int*, int*, int, int);
void MapDraw_1(int*, int*, int*, int*);
char temp[20][56];
extern char map_1[20][56] = {
	{"11111111111111111111111111111111111111111111111111"},
	{"10p01000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000001"},
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


int main() {

	LaunchManager();
	GameManager();
	return 0;
}

void LaunchManager() {
	system("mode con cols=70 lines=30 | title 제목");//최대범위 가로100 세로30
	cSystem.cursor(0);
	Menu();
}
void GameManager() {
	system("cls");
	Stage_1();
	//스테이지1~5 실행
}

int Menu() {
	//메뉴 출력
	cout << "\n\n\n\n";
	cout << " 제목을 뭘로 하지...\n";

	int x = 30, y = 15;
	cSystem.gotoxy(x - 2, y);
	cout << "> 게임 시작";
	cSystem.gotoxy(x, y + 1);
	cout << "기록 보기";
	cSystem.gotoxy(x, y + 2);
	cout << "게임 종료";
	cSystem.gotoxy(x - 20, y + 4);
	cout << "w,s를 통해 상하 이동을 하고, 스페이스바로 선택합니다!!\n";

	//메뉴 선택
	while (1) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (y > 15) {
				cSystem.gotoxy(x - 2, y);
				cout << " ";
				cSystem.gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 17) {
				cSystem.gotoxy(x - 2, y);
				cout << " ";
				cSystem.gotoxy(x - 2, ++y);
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

int keycontrol() {
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
	int x, y, mx, my;
	int on = 1;
	Monster monster_1;

	CMonster monster;

	MapDraw_1(&x, &y, &mx, &my);

	while (on) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			Move(&x, &y, 0, -1);
			monster.Move(x, y);
			break; }
		case DOWN: {
			Move(&x, &y, 0, 1);
			monster.Move(x, y);
			break; }
		case RIGHT: {
			Move(&x, &y, 1, 0);
			monster.Move(x, y);
			break; }
		case LEFT: {
			Move(&x, &y, -1, 0);
			monster.Move(x, y);
			break; }
		case SPACE:
			on = 0;
		}
	}
}


void Move(int* x, int* y, int px, int py) {//객체 생성 후 정리

	cSystem.gotoxy(*x, *y);
	cout << " ";
	cSystem.gotoxy(*x + px, *y + py);
	cout << "P";

	*x += px;
	*y += py;
}

