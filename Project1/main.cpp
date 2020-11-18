#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

#include "CMap.h"
#include "CMonster.h"
#include "CSystem.h"
#include "CCharacter.h"

using namespace std;


void LaunchManager();
int Menu();
int keycontrol();

void GameManager();
void Stage_1();


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

void Stage_1() {
	int x, y, mx, my;
	int on = 1;
	CMonster monster;
	CMap map1;
	CCharacter player;
	

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

