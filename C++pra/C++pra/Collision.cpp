#include "Collision.h"
#include"stdafx.h"
namespace Collision
{

	CollisionJudgment::CollisionJudgment()
	{

	}

	CollisionJudgment::~CollisionJudgment()
	{

	}

	bool CollisionJudgment::Circle(float x, float y, float x2, float y2, float dis)
	{
		return std::pow(x - x2, 2) + std::pow(y - y2, 2) <= std::pow(dis, 2);
	}

	bool CollisionJudgment::Circle(D3DXVECTOR2 my, D3DXVECTOR2 tag, float dis)
	{
		return std::pow(my.x - tag.x, 2) + std::pow(my.y - tag.y, 2) <= std::pow(dis, 2);
	}

	bool CollisionJudgment::Circle(float x, float y, float x2, float y2, float dis1, float dis2)
	{
		return std::pow(x - x2, 2) + std::pow(y - y2, 2) <= std::pow(dis1 + dis2, 2);
	}
}
