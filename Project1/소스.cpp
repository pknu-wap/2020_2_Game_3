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


//void PlayerInfor();//�÷��̾� �����͸� �����ͼ� ����
//void Battle();//����,�÷��̾� �����͸� �����ͼ� ����


int main(){

	LaunchManager();
	GameManager();

	return 0;
}

void LaunchManager(){
	system("mode con cols=70 lines=30 | title ����");//�ִ���� ����100 ����30
	cursor(0);
	Menu();
}
void GameManager() {
	system("cls");
	Stage_1();
	//��������1~5 ����
}



void gotoxy(int x, int y){
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
	gotoxy(x - 2, y);
	cout << "> ���� ����";
	gotoxy(x, y+1);
	cout << "��� ����";
	gotoxy(x, y+2);
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
	int x, y;
	int on = 1;

	gotoxy(0, 21);
	cout << "������ �����մϴ�!\n";
	cout << "P�� �÷��̾��� ���� ��ġ�Դϴ�." << "wsad�� �̿��� �����մϴ�.\n";
	cout << "!�� ���Ͱ� �ִ� ��ġ�Դϴ�." << "$�� �������� ��ġ�Դϴ�.\n";
	cout << "��ǥ������ G���� �̵��ϸ� ���������� Ŭ�����մϴ�!\n";

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
			else if (map_1[i][j] == 'm') {//����
				gotoxy(j, i);
				cout << "!";
			}
			else if (map_1[i][j] == 'i') {//������
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