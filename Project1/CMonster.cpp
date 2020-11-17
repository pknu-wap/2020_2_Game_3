#include "CMonster.h"

CMonster::CMonster()
{
	m_Hp = 10;

	m_PosX = 10;
	m_PosY = 10;
}

CMonster::~CMonster()
{
}


void CMonster::Move(int playerX, int playerY)
{
	cSystem.gotoxy(m_PosX, m_PosY);
	std::cout << " ";
	if (m_PosX > playerX) {
		if (m_PosY > playerY) {
			cSystem.gotoxy(m_PosX - 1, m_PosY - 1);
			std::cout << "M";
			m_PosX -= 1;
			m_PosY -= 1;
		}
		else if (m_PosY == playerY) {
			cSystem.gotoxy(m_PosX - 1, m_PosY);
			std::cout << "M";
			m_PosX -= 1;
		}
		else {
			cSystem.gotoxy(m_PosX - 1, m_PosY + 1);
			std::cout << "M";
			m_PosX -= 1;
			m_PosY += 1;
		}
	}
	else if (m_PosX == playerX) {
		if (m_PosY > playerY) {
			cSystem.gotoxy(m_PosX, m_PosY - 1);
			std::cout << "M";
			m_PosY -= 1;
		}
		else if (m_PosY == playerY) {
			cSystem.gotoxy(m_PosX, m_PosY);
			std::cout << "M";
		}
		else {
			cSystem.gotoxy(m_PosX, m_PosY + 1);
			std::cout << "M";
			m_PosY += 1;
		}
	}
	else {
		if (m_PosY > playerY) {
			cSystem.gotoxy(m_PosX + 1, m_PosY - 1);
			std::cout << "M";
			m_PosX += 1;
			m_PosY -= 1;
		}
		else if (m_PosY == playerY) {
			cSystem.gotoxy(m_PosX + 1, m_PosY);
			std::cout << "M";
			m_PosX += 1;
		}
		else {
			cSystem.gotoxy(m_PosX + 1, m_PosY + 1);
			std::cout << "M";
			m_PosX += 1;
			m_PosY -= 1;
		}
	}
}