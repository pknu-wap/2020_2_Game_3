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

void CSystem::cursor(int n){ // Ŀ�� ���̱� & �����
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor; //����ü ���� 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n; //Ŀ�� ���⿩�� 1:����, 0:�Ⱥ��� 
	ConsoleCursor.dwSize = 1; //Ŀ�� ������ 
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