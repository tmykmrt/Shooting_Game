#pragma once
#include"stdafx.h"

class Collision
{
public:
	Collision();
	~Collision();
	static bool Circle(float x,float y, float x2, float y2,float dis);
	static bool Circle(D3DXVECTOR2 my, D3DXVECTOR2 tag,float dis);
};

