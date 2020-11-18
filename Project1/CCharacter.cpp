#include "CCharacter.h"

CCharacter::CCharacter()
{
	c_Hp = 10;

	c_PosX = 10;
	c_PosY = 10;
}

CCharacter::~CCharacter()
{

}

void CCharacter::Move(int* x, int* y, int px, int py) {

	cSystem.gotoxy(*x, *y);
	std::cout << " ";
	cSystem.gotoxy(*x + px, *y + py);
	std::cout << "P";

	*x += px;
	*y += py;
}