#include "CMonster.h"

CMonster::CMonster(int x,int y,int hp)
{
	m_Hp = hp;

	m_PosX = x;
	m_PosY = y;
}

CMonster::~CMonster()
{

}

void CMonster::Detect(int px,int py,int mx,int my) {
	if (px > mx)
	{
		mx += 1;
		if (py > my)	my += 1;
		else if (py < my) my -= 1;
	}
	else if(px=mx)
	{
		mx = mx;
		if (py > my)	my += 1;
		else if (py < my) my -= 1;
	}
	else if (px < mx)
	{
		mx -= 1;
		if (py > my)	my += 1;
		else if (py < my) my -= 1;
	}
}