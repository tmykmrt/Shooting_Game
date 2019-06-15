#pragma once
#include"Shape.h"
namespace Collision
{
	class CollisionFactory
	{
	public:
		struct ShapeData
		{
			Collision::ShapeType type;
			float radiu;
			float top;
			float buttom;
			float right;
			float left;
		};

		CollisionFactory();
		~CollisionFactory();
		Shape *Create(ShapeData data);
	private:

	};
}
