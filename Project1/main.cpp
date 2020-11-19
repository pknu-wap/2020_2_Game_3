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

void GameManager();
void Stage_1();


int main() {

	LaunchManager();
	GameManager();
	return 0;
}

void LaunchManager() {
	system("mode con cols=70 lines=30 | title ����");//�ִ���� ����100 ����30
	cSystem.cursor(0);
	Menu();
}
void GameManager() {
	system("cls");
	Stage_1();
	//��������1~5 ����
}

int Menu() {
	//�޴� ���
	cout << "\n\n\n\n";
	cout << " ������ ���� ����...\n";

	int x = 30, y = 15;
	cSystem.gotoxy(x - 2, y);
	cout << "> ���� ����";
	cSystem.gotoxy(x, y + 1);
	cout << "��� ����";
	cSystem.gotoxy(x, y + 2);
	cout << "���� ����";
	cSystem.gotoxy(x - 20, y + 4);
	cout << "w,s�� ���� ���� �̵��� �ϰ�, �����̽��ٷ� �����մϴ�!!\n";

	//�޴� ����
	while (1) {
		int n = cSystem.keycontrol();
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
	int on = 1;

	CMonster monster;
	CMap map1;
	CCharacter player;
	
	map1.mapping();
	map1.get_map();

	while (on) {
		int n = cSystem.keycontrol();
		switch (n) {
		case UP: {
			if (map1.newMap[map1.c_y - 1][map1.c_x] == '#')
			{
				player.Move(&map1.c_x, &map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&map1.c_x, &map1.c_y, 0, -1);
			}
			monster.Move(&map1.m_x, &map1.m_y, &map1.c_x, &map1.c_y);
			break; }
		case DOWN: {
			if (map1.newMap[map1.c_y + 1][map1.c_x] == '#')
			{
				player.Move(&map1.c_x, &map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&map1.c_x, &map1.c_y, 0, 1);
			}
			monster.Move(&map1.m_x, &map1.m_y, &map1.c_x, &map1.c_y);
			break; }
		case RIGHT: {
			if (map1.newMap[map1.c_y][map1.c_x + 1] == '#')
			{
				player.Move(&map1.c_x, &map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&map1.c_x, &map1.c_y, 1, 0);
			}
			monster.Move(&map1.m_x, &map1.m_y, &map1.c_x, &map1.c_y);
			break; }
		case LEFT: {
			if (map1.newMap[map1.c_y][map1.c_x - 1] == '#')
			{
				player.Move(&map1.c_x, &map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&map1.c_x, &map1.c_y, -1, 0);
			}
			monster.Move(&map1.m_x, &map1.m_y, &map1.c_x, &map1.c_y);
			break; }
		case SPACE:
			on = 0;
		}
	}
}

