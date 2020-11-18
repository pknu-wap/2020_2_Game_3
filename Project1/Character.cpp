#include <iostream>
#include <conio.h>
#include "Character.h"

using namespace std;

constexpr auto UP = 1;
constexpr auto DOWN = 2;
constexpr auto RIGHT = 3;
constexpr auto LEFT = 4;
constexpr auto SPACE = 0;

void Character::Move(int* x, int* y, int px, int py)
{
	gotoxy(*x, *y);
	cout << " ";
	gotoxy(*x + px, *y + py);
	cout << "P";

	*x += px;
	*y += py;
}

void Character::CharacterMove()
{
	int x, y;
	int on = 1;

	while (on) {
		int n = keycontrol();
		switch (n) {
		case UP: {
			if (map_1[y - 1][x] == '1')
			{
				Move(&x, &y, 0, 0);
			}
			else
			{
				Move(&x, &y, 0, -1);
			}
			break;
		}
		case DOWN: {
			if (map_1[y + 1][x] == '1')
			{
				Move(&x, &y, 0, 0);
			}
			else
			{
				Move(&x, &y, 0, 1);
			}
			break;
		}
		case RIGHT: {
			if (map_1[y][x + 1] == '1')
			{
				Move(&x, &y, 0, 0);
			}
			else
			{
				Move(&x, &y, 1, 0);
			}
			break;
		}
		case LEFT: {
			if (map_1[y][x - 1] == '1')
			{
				Move(&x, &y, 0, 0);
			}
			else
			{
				Move(&x, &y, -1, 0);
			}
			break;
		}
		case SPACE:
			on = 0;
		}
	}
}

int Character::keycontrol()
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