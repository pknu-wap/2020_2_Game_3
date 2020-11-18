#include "Character.h"

char map_1[20][56];

Character::Character()
{
	c_PosX = 5;
	c_PosY = 5;
}

Character::~Character()
{

}

void Character::Move(int* x, int* y, int px, int py)
{
	cSystem.gotoxy(*x, *y);
	cout << " ";
	cSystem.gotoxy(*x + px, *y + py);
	cout << "P";

	*x += px;
	*y += py;
}

void Character::CharacterMove()
{
	int on = 1;

	while (on) {
		int n = cSystem.keycontrol();
		switch (n) {
		case UP: {
			if (map_1[c_PosY - 1][c_PosX] == '1')
			{
				Move(&c_PosX, &c_PosY, 0, 0);
			}
			else
			{
				Move(&c_PosX, &c_PosY, 0, -1);
			}
			break;
		}
		case DOWN: {
			if (map_1[c_PosY + 1][c_PosX] == '1')
			{
				Move(&c_PosX, &c_PosY, 0, 0);
			}
			else
			{
				Move(&c_PosX, &c_PosY, 0, 1);
			}
			break;
		}
		case RIGHT: {
			if (map_1[c_PosY][c_PosX + 1] == '1')
			{
				Move(&c_PosX, &c_PosY, 0, 0);
			}
			else
			{
				Move(&c_PosX, &c_PosY, 1, 0);
			}
			break;
		}
		case LEFT: {
			if (map_1[c_PosY][c_PosX - 1] == '1')
			{
				Move(&c_PosX, &c_PosY, 0, 0);
			}
			else
			{
				Move(&c_PosX, &c_PosY, -1, 0);
			}
			break;
		}
		case SPACE:
			on = 0;
		}
	}
}