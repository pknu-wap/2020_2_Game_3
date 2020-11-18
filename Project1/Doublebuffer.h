#pragma once
#include <Windows.h>

class Doublebuffer
{
public:
	Doublebuffer();
	~Doublebuffer();

public:
	void CreateBuffer();
	void WriteBuffer(int x, int y, char str[]);
	void FlipBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};

