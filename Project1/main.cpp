#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <chrono>
#include <cstdint>

#include "CMonster.h"
#include "CSystem.h"
#include "CCharacter.h"
#include "DoubleBuffer.h"

using namespace std;


void LaunchManager();

void Stage_1(Doublebuffer& db);
void mapping(Doublebuffer& db);
void DrawMap(Doublebuffer& db);

void GameManager();


enum GAMESTATE {
	GAMEMENU,
	GAMEMAIN,
	GAMEEND
};

GAMESTATE state = GAMESTATE::GAMEMENU;
CCharacter player;
CMonster monster;
static bool map[30][70];


int main() {

	LaunchManager();
	GameManager();
	return 0;
}

void Render(Doublebuffer& db) {
	switch (state) {
	case GAMESTATE::GAMEMENU:
		// 렌더링, writeBuffer, 맵 그리기
		// WriteBuffer(x좌표, y좌표, 그릴 문자열);
		// 메뉴 렌더링
		db.WriteBuffer(0, 1, "GAMEMENU");
		mapping(db);
		break;
	case GAMESTATE::GAMEMAIN:
		db.WriteBuffer(0, 1, "GAMEMAIN");
		// 스테이지 렌더링
		db.WriteBuffer(0, 30, "Stage 1");
		//맵그리기
		DrawMap(db);
		db.WriteBuffer(player.c_PosX, player.c_PosY, "P");
		db.WriteBuffer(monster.m_PosX, monster.m_PosY, "M");


		break;
	case GAMESTATE::GAMEEND:
		db.WriteBuffer(0, 1, "GAMEEND");

		// 게임오버 됐을 때 렌더링
		break;
	}
}

void Update(Doublebuffer& db)
{
	bool w = (GetAsyncKeyState(0x57) & 0x8000);
	bool s = (GetAsyncKeyState(0x53) & 0x8000);
	bool a = (GetAsyncKeyState(0x41) & 0x8000);
	bool d = (GetAsyncKeyState(0x44) & 0x8000);
	bool space = (GetAsyncKeyState(0x20) & 0x8000);

	// 로직 처리
	// 입력 또는 충돌처리
	switch (state) {
	case GAMESTATE::GAMEMENU:
		db.WriteBuffer(30, 15, "  게임 시작");
		db.WriteBuffer(30, 16, "  게임 종료");
		if (w == true) {
			db.WriteBuffer(30, 15, ">");
		}
		else if (s == true) {
			db.WriteBuffer(30, 16, ">");
		}
		if (space == true) {
			state = GAMEMAIN;
		}
		break;
	case GAMESTATE::GAMEMAIN:
		//플레이어 이동
		if (w == true && map[player.c_PosY - 1][player.c_PosX] == true) player.c_PosY -= 1;
		else if (s == true && map[player.c_PosY + 1][player.c_PosX] == true) player.c_PosY += 1;
		else if (a == true && map[player.c_PosY][player.c_PosX - 1] == true) player.c_PosX -= 1;
		else if (d == true && map[player.c_PosY][player.c_PosX + 1] == true) player.c_PosX += 1;
		
		break;
	case GAMESTATE::GAMEEND:
		break;
	}
}

void LaunchManager() {
	system("mode con cols=71 lines=36 | title 제목");//최대범위 가로100 세로30
	cSystem.cursor(0);
}

void GameManager() {
	const int fps = 120;

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

			// Render 상태 패턴

			doubleBuffer.WriteBuffer(0, 0, ss.str());
			Render(doubleBuffer);
			Update(doubleBuffer);

			// -----

			doubleBuffer.FlipBuffer();
			doubleBuffer.ClearBuffer();
		}
	}

	//스테이지1~5 실행
}

void mapping(Doublebuffer& db)
{
	srand(time(NULL));
	int SetMap = 450;

	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 70; x++) {
			if (rand() % 1000 < SetMap) {
				map[y][x] = true;
			}
			else {
				map[y][x] = false;
			}
		}
	}
	bool temp_map[30][70];

	for (int k = 0; k < 3; k++) {
		for (int y = 0; y < 30; y++) {
			for (int x = 0; x < 70; x++) {
				int count = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						int nx = x + i;
						int ny = y + j;

						if (i == 0 && j == 0) {
							//카운트하지 않음
						}

						else if (nx < 0 || ny < 0 || nx >= 70 || ny >= 30) {
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

		for (int y = 0; y < 30; y++) {
			for (int x = 0; x < 70; x++) {
				map[y][x] = temp_map[y][x];
			}
		}
	}
	//출력
	
}

void DrawMap(Doublebuffer& db)
{
	//맵출력
	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 70; x++) {
			if (x == 0 || y == 0 || x == 69 || y == 29) {
				db.WriteBuffer(x, y, "#");
			}
			else if (map[y][x] == true) {
				db.WriteBuffer(x, y, " ");
			}
			else {
				db.WriteBuffer(x, y, "#");
			}
		}
	}
}

void Stage_1(Doublebuffer& db)
{

}