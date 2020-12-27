#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

#include "CSystem.h"

class CMonster
{
public:
	int		m_Hp;

	int		m_PosX;
	int		m_PosY;

public:
	CMonster(int posx, int posy, int hp);
	~CMonster();

public:
	void Detect(int px, int py, int mx, int my);
};