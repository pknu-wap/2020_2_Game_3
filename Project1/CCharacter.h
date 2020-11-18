#pragma once
#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

#include "CSystem.h"

class CCharacter
{
public:
	CCharacter();
	~CCharacter();

public:
	int		c_Hp;
	
	int		c_PosX;
	int		c_PosY;
public:
	void Move(int*, int*, int, int);
};

