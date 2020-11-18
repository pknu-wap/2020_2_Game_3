#include "CSystem.h"

CSystem::CSystem()
{
}

CSystem::~CSystem()
{
}

void CSystem::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void CSystem::cursor(int n){ // 커서 보이기 & 숨기기
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor; //구조체 선언 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; //커서 노출여부 1:보임, 0:안보임 
	ConsoleCursor.dwSize = 1; //커서 사이즈 
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int CSystem::keycontrol()
{
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