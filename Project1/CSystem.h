#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

constexpr auto UP = 1;
constexpr auto DOWN = 2;
constexpr auto RIGHT = 3;
constexpr auto LEFT = 4;
constexpr auto SPACE = 0;

class CSystem
{
public:
	CSystem();
	~CSystem();

public:
	void gotoxy(int x, int y);
	void cursor(int n);
	int keycontrol();
};

static CSystem cSystem;