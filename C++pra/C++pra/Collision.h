#pragma once
#include"stdafx.h"

namespace Collision
{
	class CollisionJudgment
	{
	public:
		CollisionJudgment();
		~CollisionJudgment();
		static bool Circle(float x, float y, float x2, float y2, float dis);
		static bool Circle(D3DXVECTOR2 my, D3DXVECTOR2 tag, float dis);
		static bool Circle(float x, float y, float x2, float y2, float dis1, float dis2);
	};
}
