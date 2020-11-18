#pragma once
#include <iostream>
#include "CSystem.h"

using namespace std;

class Character
{
public:
	int c_PosX;
	int c_PosY;

public:
	Character();
	~Character();

public:
	void Move(int* x, int* y, int px, int py);
	void CharacterMove();
};

