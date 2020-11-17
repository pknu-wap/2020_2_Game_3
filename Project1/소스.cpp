#include <iostream>
#include <conio.h>
#include <CoreWindow.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

constexpr auto UP = 1;
constexpr auto DOWN = 2;
constexpr auto RIGHT = 3;
constexpr auto LEFT = 4;
constexpr auto SPACE = 0;

class Player {
public:
	int x, y;
	int HP;
	int AP;
	void Move(int* x, int* y, int px, int py);

};

class Monster {
public:
	int x, y;
	int HP;
	int AP;
	void Move(int* x, int* y, int* mx, int* my);
};

class Map {
public:
	void MapDraw_1(int*, int*, int*, int*);
	void Draw(int*, int*, int*, int*);
};


int Menu();
void gotoxy(int, int);
int keycontrol();
void cursor(int);

void GameManager();
void Stage_1();
char temp[20][56];
char map_1[20][56] = {
	{"11111111111111111111111111111111111111111111111111"},
	{"10p01000000000000000000000000000000000001111000001"},
	{"10001000000000000000000000000000000000000011000001"},
	{"10001000000000000000000000000000000000000001000001"},
	{"10001000111111111111111111110000000000000010000001"},
	{"10001000000000000000000000000000000000000010000001"},
	{"10001000000000000000000000000000000000000100000001"},
	{"10000000000000000000000000000000000000001000000001"},
	{"11111000000000000000000000000000000000010000000001"},
	{"10001000000000000000000000000000000000100000000001"},
	{"100i1000000000000000000000000000000001000000000001"},
	{"10111000000000000010000000000000000000000000000001"},
	{"10000000000000000010000000000000000000000000000001"},
	{"11111000000000000010000000000000001000000000000001"},
	{"1000100000000000001000000000m000010000000000000001"},
	{"10001111111111111111111111111111111111111111000001"},
	{"10000100000000000000000000000000000001000000000001"},
	{"10000100000000000000000000000000000001000000000g01"},
	{"10000100000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111"},
};


//void PlayerInfor();//플레이어 데이터를 가져와서 진행
//void Battle();//몬스터,플레이어 데이터를 가져와서 진행


int main() {

	Menu();
	GameManager();

	return 0;
}


void GameManager() {
	system("cls");
	Stage_1();
	//스테이지1~5 실행
}

void gotoxy(int x, int y) {
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


int Menu() {

	system("mode con cols=70 lines=30 | title 제목");//최대범위 가로100 세로30
	cursor(0);

	//메뉴 출력
	cout << "\n\n\n\n";
	cout << " 제목을 뭘로 하지...\n";

	int x = 30, y = 15;
	gotoxy(x - 2, y);
	cout << "> 게임 시작";
	gotoxy(x, y + 1);
	cout << "기록 보기";
	gotoxy(x, y + 2);
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
void Stage_1() {
	int on = 1;
	Player p;
	Monster mon1;
	Map map1;

	gotoxy(0, 21);
	cout << "게임을 시작합니다!\n";
	cout << "P는 플레이어의 현재 위치입니다." << "wsad를 이용해 조작합니다.\n";
	cout << "!는 몬스터가 있는 위치입니다." << "$는 아이템의 위치입니다.\n";
	cout << "목표지점인 G까지 이동하면 스테이지를 클리어합니다!\n";

	map1.MapDraw_1(&p.x, &p.y, &mon1.x, &mon1.y);
	//void map(player1.x

	while (on) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (map_1[p.y - 1][p.x] == '1')
			{
				p.Move(&p.x, &p.y, 0, 0);
			}
			else {
				p.Move(&p.x, &p.y, 0, -1);
				mon1.Move(&mon1.x, &mon1.y, &p.x, &p.y);
			}
			break; }
		case DOWN: {
			if (map_1[p.y + 1][p.x] == '1')
			{
				p.Move(&p.x, &p.y, 0, 0);
			}
			else {
				p.Move(&p.x, &p.y, 0, 1);
				mon1.Move(&mon1.x, &mon1.y, &p.x, &p.y);
			}
			break; }
		case RIGHT: {
			if (map_1[p.y][p.x + 1] == '1')
			{
				p.Move(&p.x, &p.y, 0, 0);
			}
			else {
				p.Move(&p.x, &p.y, 1, 0);
				mon1.Move(&mon1.x, &mon1.y, &p.x, &p.y);
			}
			break; }
		case LEFT: {
			if (map_1[p.y][p.x - 1] == '1')
			{
				p.Move(&p.x, &p.y, 0, 0);
			}
			else {
				p.Move(&p.x, &p.y, -1, 0);
				mon1.Move(&mon1.x, &mon1.y, &p.x, &p.y);
			}
			break; }
		case SPACE:
			on = 0;
		}
	}
}


void Map::MapDraw_1(int* x, int* y, int* mx, int* my) {
	int i, j;
	int a, b;
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
			else if (map_1[i][j] == 'i') {//아이템
				gotoxy(j, i);
				cout << "$";
			}
		}
	}
	for (a = 0; a < 20; a++) {
		for (b = 0; b < 56; b++) {
			if (map_1[a][b] == 'm') {//몬스터
				gotoxy(b, a);
				cout << "!";
				*mx = b;
				*my = a;
			}
		}
	}
}
void Map::Draw(int* x, int* y, int* mx, int* my)
{
	system(" mode  con   cols=141 ");
	srand(time(NULL));
	int set_map = 420;	//���� Ŭ���� ���� ���� �پ��

	bool map[50][140];
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			if (rand() % 1000 < set_map) {
				map[y][x] = true;
			}
			else {
				map[y][x] = false;
			}
		}
	}
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 140; x++) {
			//cout << map[y][x];		//���ڷ� ����

			if (map[y][x] == true) {	//���ڷ� ����
				cout << ' ';
			}
			else {
				cout << '#';
			}

		}
		cout << '\n';
	}
	cout << "\n\n\n";

	bool temp_map[50][140];

	for (int k = 0; k < 1; k++) {
		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				int count = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						int nx = x + i;
						int ny = y + j;

						if (i == 0 && j == 0) {
							//ī��Ʈ���� ����
						}

						else if (nx < 0 || ny < 0 || nx >= 140 || ny >= 50) {
							count = count + 1;
						}

						else if (map[ny][nx] != true) {
							count = count + 1;
						}
					}
				}
				if (count < 5) {
					temp_map[y][x] = true;
				}
				else {
					temp_map[y][x] = false;
				}
			}
		}

		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				map[y][x] = temp_map[y][x];
			}
		}

		for (int y = 0; y < 50; y++) {
			for (int x = 0; x < 140; x++) {
				//cout << map[y][x];			//���ڷ� ����
				if (x == 0 || y == 0 || x == 139 || y == 49) {
					cout << '#';
				}
				else if (map[y][x] == true) {	//���ڷ� ����
					cout << ' ';
				}
				else {
					cout << '#';
				}
			}
			cout << '\n';
		}
		cout << "\n\n\n";
	}

}


void Player::Move(int* x, int* y, int px, int py) {
	
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
