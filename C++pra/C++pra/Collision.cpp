#include "Collision.h"
#include"stdafx.h"

Collision::Collision()
{

}

Collision::~Collision()
{
	
}

bool Collision::Circle(float x, float y, float x2, float y2, float dis)
{
	return std::pow(x - x2,2) + std::pow(y - y2,2) <= std::pow(dis,2);
}

bool Collision::Circle(D3DXVECTOR2 my, D3DXVECTOR2 tag, float dis)
{
	return std::pow(my.x - tag.x, 2) + std::pow(my.y - tag.y, 2) <= std::pow(dis, 2);
}
