#include "CollisionFactory.h"
#include "CollisionManager.h"
#include "CircleShape.h"
#include "RectShape.h"
#include "Shape.h"
namespace  Collision
{
	CollisionFactory::CollisionFactory()
	{

	}

	CollisionFactory::~CollisionFactory()
	{

	}

	//	
	Collision::Shape *CollisionFactory::Create(ShapeData data)
	{
		Shape *createShape = nullptr;
		switch (data.type)
		{
		case ShapeType::Circle:
			createShape = new CircleShape(data.radiu);
			break;
		case ShapeType::Rect:
			createShape = new RectShape(data.left, data.buttom, data.right, data.top);
			break;
		}
		CollisionManager::GetInstance()->Add(createShape);
		return createShape;
	}
}
