#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

class CMap
{
public:
	CMap();
	~CMap();
public:
	char newMap[50][140];
public:
	void mapping();
	void get_map();
};