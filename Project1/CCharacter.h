#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "CSystem.h"

class CCharacter
{
public:
	CCharacter();
	~CCharacter();

public:
	int		c_Hp;
	int		c_Pp;

	int		c_PosX;
	int		c_PosY;
};

