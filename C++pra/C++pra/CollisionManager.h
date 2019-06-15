#pragma once
#include"stdafx.h"
#include"Singleton.h"
#include"Shape.h"

namespace Collision
{
	class CollisionManager : public Singleton<CollisionManager>
	{
	public:
		friend class Singleton<CollisionManager>;
		void Add(Shape *shape);
		//
		void CollisionCheck();
	protected:
		CollisionManager();
		~CollisionManager();
	private:
		//	�A�N�e�B�u�ȃR���W����
		list<Shape*> shapeList;
	};
}
