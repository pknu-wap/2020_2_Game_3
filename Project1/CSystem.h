#pragma once
#include <iostream>
#include <conio.h>
#include <CoreWindow.h>

class CSystem
{
public:
	CSystem();
	~CSystem();

public:
	void gotoxy(int x, int y);
	void cursor(int n);
};

static CSystem cSystem;