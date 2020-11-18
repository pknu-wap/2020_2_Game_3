#include "Doublebuffer.h"

Doublebuffer::Doublebuffer()
{

}

Doublebuffer::~Doublebuffer() {

}

#define MAP_X_MAX 141
#define MAP_Y_MAX 30

HANDLE hBuffer[2];
int nScreenIndex;

void  Doublebuffer::CreateBuffer() {//���� ����

	COORD size = { MAP_X_MAX, MAP_Y_MAX };
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = MAP_X_MAX - 1;;
	rect.Top = MAP_Y_MAX - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

}

void Doublebuffer::WriteBuffer(int x, int y, char str[])//����� �׸���
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
	WriteFile(hBuffer[nScreenIndex], str, strlen(str), &dw, NULL);

}
void Doublebuffer::FlipBuffer()//���� ��ȯ
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}

void Doublebuffer::ClearBuffer()//ȭ�� �����
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', MAP_X_MAX * MAP_Y_MAX, Coor, &dw);
}

void Doublebuffer::DeleteBuffer() {//���� ����
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}