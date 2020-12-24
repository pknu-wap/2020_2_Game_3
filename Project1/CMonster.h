#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "CSystem.h"

class CMonster
{
public:
	int		m_Hp;

	int		m_PosX;
	int		m_PosY;

public:
	CMonster();
	~CMonster();
};