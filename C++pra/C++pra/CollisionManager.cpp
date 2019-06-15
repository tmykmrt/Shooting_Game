#include "CollisionManager.h"
#include "Shape.h"
#include "CircleShape.h"
#include "RectShape.h"
#include "Collision.h"

namespace Collision
{

	CollisionManager::CollisionManager()
	{

	}

	CollisionManager::~CollisionManager()
	{
		std::list<Shape *>::iterator it;
		for (it = shapeList.begin(); it != shapeList.end(); it++)
		{
			delete (*it);
		}
	}

	void CollisionManager::Add(Shape *shape)
	{
		shapeList.push_back(shape);
	}

	bool CircleAndCircle(CircleShape &shape, CircleShape &shape2);
	void CollisionManager::CollisionCheck()
	{
		list<Shape*>::iterator itr;
		list<Shape*>::iterator itr2;

		for (itr = shapeList.begin(); itr != shapeList.end(); itr++)
		{
			for (itr2 = shapeList.begin(); itr2 != shapeList.end(); itr2++)
			{
				if ((*itr) == (*itr2))
				{
					continue;
				}

				if ((*itr)->GetType() == ShapeType::Circle
					&& (*itr2)->GetType() == ShapeType::Circle)
				{
					//	円と円
					//	スマートじゃないかも
					//	他の方法がないか
					if (CircleAndCircle((CircleShape&)itr, (CircleShape&)itr2))
					{
						//(*itr2)->Hit();
					}
				}
				else if ((*itr)->GetType() == ShapeType::Circle
					&& (*itr2)->GetType() == ShapeType::Rect)
				{
					//	円と矩形
				}
				else if ((*itr)->GetType() == ShapeType::Rect
					&& (*itr2)->GetType() == ShapeType::Rect)
				{
					//	矩形と矩形
				}
			}
		}
	}

	bool CircleAndCircle(CircleShape &shape, CircleShape &shape2)
	{
		return Collision::CollisionJudgment::Circle(shape.GetX(), shape.GetY(),
			shape2.GetX(), shape2.GetY(), shape.GetRadius(), shape2.GetRadius());
	}
}
