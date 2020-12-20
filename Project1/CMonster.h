#pragma once
#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

#include "CSystem.h"
#include "CMap.h"

class CMonster
{
public:
	int		m_Hp;

	int		m_PosX;
	int		m_PosY;
	CMap map1;

public:
	CMonster();
	~CMonster();

public:
	void Move(int* m_PosX, int* m_PosY, int* playerX, int* playerY);
};