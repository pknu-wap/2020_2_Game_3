#pragma once
class Character{
public:
	Character();
	~Character();
public:
	void Move(int* x, int* y, int px, int py);
	void CharacterMove();
	int keycontrol();
};

