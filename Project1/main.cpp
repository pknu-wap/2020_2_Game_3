#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <chrono>
#include <cstdint>

#include "CMap.h"
#include "CMonster.h"
#include "CSystem.h"
#include "CCharacter.h"
#include "DoubleBuffer.h"

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
	system("mode con cols=70 lines=30 | title 제목");//최대범위 가로100 세로30
	cSystem.cursor(0);
	Menu();
}

void GameManager() {
	const int fps = 30;

	using frame = std::chrono::duration<int32_t, std::ratio<1, fps>>;
	using ms = std::chrono::duration<float, std::milli>;

	std::chrono::time_point<std::chrono::steady_clock> fpsTimer(std::chrono::steady_clock::now());

	frame FPS{};

	Doublebuffer doubleBuffer;
	doubleBuffer.CreateBuffer();

	while (true) {
		FPS = std::chrono::duration_cast<frame>(std::chrono::steady_clock::now() - fpsTimer);

		if (FPS.count() >= 1) {
			fpsTimer = std::chrono::steady_clock::now();

			std::stringstream ss("");
			ss << FPS.count() * fps << " fps  " << std::chrono::duration_cast<ms>(FPS).count() << "ms";

			doubleBuffer.WriteBuffer(0, 0, ss.str());

			Stage_1();

			doubleBuffer.FlipBuffer();
			doubleBuffer.ClearBuffer();
		}
	}
	
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
	//CMap map1;
	CCharacter player;
	
	//map1.mapping();
	//map1.get_map();

	while (on) {
		int n = cSystem.keycontrol();
		switch (n) {
		case UP: {
			if (monster.map1.newMap[monster.map1.c_y - 1][monster.map1.c_x] == '#')
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, -1);
			}
			monster.Move(&monster.map1.m_x, &monster.map1.m_y, &monster.map1.c_x, &monster.map1.c_y);
			break; }
		case DOWN: {
			if (monster.map1.newMap[monster.map1.c_y + 1][monster.map1.c_x] == '#')
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, 1);
			}
			monster.Move(&monster.map1.m_x, &monster.map1.m_y, &monster.map1.c_x, &monster.map1.c_y);
			break; }
		case RIGHT: {
			if (monster.map1.newMap[monster.map1.c_y][monster.map1.c_x + 1] == '#')
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 1, 0);
			}
			monster.Move(&monster.map1.m_x, &monster.map1.m_y, &monster.map1.c_x, &monster.map1.c_y);
			break; }
		case LEFT: {
			if (monster.map1.newMap[monster.map1.c_y][monster.map1.c_x - 1] == '#')
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, 0, 0);
			}
			else
			{
				player.Move(&monster.map1.c_x, &monster.map1.c_y, -1, 0);
			}
			monster.Move(&monster.map1.m_x, &monster.map1.m_y, &monster.map1.c_x, &monster.map1.c_y);
			break; }
		case SPACE:
			on = 0;
		}
	}
}

