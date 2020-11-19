#pragma once
#include <Windows.h>
#include <string>

class Doublebuffer
{
public:
	Doublebuffer();
	~Doublebuffer();

public:
	void CreateBuffer();
	void WriteBuffer(int x, int y, std::string str);
	void FlipBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};

