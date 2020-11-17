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
void gotoxy(int, int);
int keycontrol();
void cursor(int);

void GameManager();
void Stage_1();
void Move(int*, int*, int, int);
void MapDraw_1(int*, int*, int*, int*);
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


//void PlayerInfor();//�÷��̾� �����͸� �����ͼ� ����
//void Battle();//����,�÷��̾� �����͸� �����ͼ� ����


int main() {

	LaunchManager();
	GameManager();
	return 0;
}

void LaunchManager() {
	system("mode con cols=70 lines=30 | title ����");//�ִ���� ����100 ����30
	cursor(0);
	Menu();
}
void GameManager() {
	system("cls");
	Stage_1();
	//��������1~5 ����
}



void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void cursor(int n) {  // Ŀ�� ���̱� & �����
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor; //����ü ���� 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; //Ŀ�� ���⿩�� 1:����, 0:�Ⱥ��� 
	ConsoleCursor.dwSize = 1; //Ŀ�� ������ 
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int Menu() {
	//�޴� ���
	cout << "\n\n\n\n";
	cout << " ������ ���� ����...\n";

	int x = 30, y = 15;
	cSystem.gotoxy(x - 2, y);
	cout << "> ���� ����";
	gotoxy(x, y + 1);
	cout << "��� ����";
	gotoxy(x, y + 2);
	cout << "���� ����";
	gotoxy(x - 20, y + 4);
	cout << "w,s�� ���� ���� �̵��� �ϰ�, �����̽��ٷ� �����մϴ�!!\n";

	//�޴� ����
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

/*GameRecord���� ���� �̻��ϴ�...
//void GameRecord(){
	int n = keycontrol();
	system("cls");
	//���� ��� �ҷ�����
	cout << "���� ����� ����غ���!!\n" << "�Ѿ���� �����̽��ٸ� ��������...\n";
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

	gotoxy(0, 21);
	cout << "������ �����մϴ�!\n";
	cout << "P�� �÷��̾��� ���� ��ġ�Դϴ�." << "wsad�� �̿��� �����մϴ�.\n";
	cout << "!�� ���Ͱ� �ִ� ��ġ�Դϴ�." << "$�� �������� ��ġ�Դϴ�.\n";
	cout << "��ǥ������ G���� �̵��ϸ� ���������� Ŭ�����մϴ�!\n";

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
void MapDraw_1(int* x, int* y, int* mx, int* my) {
	int i, j;
	int a, b;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 56; j++) {
			if (map_1[i][j] == '0') {
				gotoxy(j, i);
				cout << " ";
			}
			else if (map_1[i][j] == '1') {		//����
				gotoxy(j, i);
				cout << "*";
			}
			else if (map_1[i][j] == 'p') {//������
				gotoxy(j, i);
				cout << "P";
				*x = j;
				*y = i;
			}
			else if (map_1[i][j] == 'g') {//��ǥ����
				gotoxy(j, i);
				cout << "G";
			}
			else if (map_1[i][j] == 'i') {//������
				gotoxy(j, i);
				cout << "$";
			}
		}
	}
	for (a = 0; a < 20; a++) {
		for (b = 0; b < 56; b++) {
			if (map_1[a][b] == 'm') {//����
				gotoxy(b, a);
				cout << "!";
				*mx = b;
				*my = a;
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

void Monster::Move(int* mx, int* my, int* x, int* y) {
	gotoxy(*mx, *my);
	cout << " ";
	if (*mx > * x) {
		if (*my > * y) {
			gotoxy(*mx - 1, *my - 1);
			cout << "M";
			*mx -= 1;
			*my -= 1;
		}
		else if (*my = *y) {
			gotoxy(*mx - 1, *my);
			cout << "M";
			*mx -= 1;
		}
		else {
			gotoxy(*mx - 1, *my + 1);
			cout << "M";
			*mx -= 1;
			*my += 1;
		}
	}
	else if (*mx = *x) {
		if (*my > * y) {
			gotoxy(*mx, *my - 1);
			cout << "M";
			*my -= 1;
		}
		else if (*my = *y) {
			gotoxy(*mx, *my);
			cout << "M";
		}
		else {
			gotoxy(*mx, *my + 1);
			cout << "M";
			*my += 1;
		}
	}
	else {
		if (*my > * y) {
			gotoxy(*mx + 1, *my - 1);
			cout << "M";
			*mx += 1;
			*my -= 1;
		}
		else if (*my = *y) {
			gotoxy(*mx + 1, *my);
			cout << "M";
			*mx += 1;
		}
		else {
			gotoxy(*mx + 1, *my + 1);
			cout << "M";
			*mx += 1;
			*my -= 1;
		}
	}
}