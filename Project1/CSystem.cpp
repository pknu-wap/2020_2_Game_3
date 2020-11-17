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
