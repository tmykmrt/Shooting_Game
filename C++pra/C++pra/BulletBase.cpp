#include "BulletBase.h"
#include "CollisionFactory.h"
#include "Shape.h"

using namespace Collision;
class BulletManager;

namespace Unit
{
	namespace Bullet
	{
		BulletBase::BulletBase()
		{

		}

		BulletBase::BulletBase(float speed, UnitType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
		{
			sprite.Load("Res/bullet_01.png", 32, 32);
			Init(speed, targetType, moveType, startPos, targtPos);
		}

		BulletBase::~BulletBase()
		{
			UnitBase::~UnitBase();
		}

		UnitType BulletBase::GetTargetType()
		{
			return targetType;
		}

		void BulletBase::Init(float speed, UnitType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
		{
			position = startPos;
			this->speed = speed;
			nowSpeed = this->speed;
			this->targetType = targetType;
			exists = true;
			hp = 1;
			if (moveType == 1)
			{
				vec.x = 1;
				vec.y = 0;
			}
			if (moveType == 2)
			{
				float atan = atan2f(targtPos.y - startPos.y, targtPos.x - startPos.x);
				vec.x = cosf(atan);
				vec.y = sinf(atan);
			}
			if (moveType == 3)
			{
				vec.x = 1;
				vec.y = 1;
			}
			CollisionFactory::ShapeData shapeData;
			shapeData.type = ShapeType::Circle;
			shapeData.radiu = 32;
			CreateShape();
		}

		void BulletBase::CreateShape()
		{
			Collision::CollisionFactory *factry = new CollisionFactory();
			Collision::CollisionFactory::ShapeData data;
			data.radiu = 64.0f;
			data.type = Collision::ShapeType::Circle;
			shape = factry->Create(data);
			delete factry;
		}

		void BulletBase::Update()
		{
			UpdatePosition();
			if (CheckScreenOut())
			{
				Deleat();
			}
		}

		void BulletBase::Render()
		{
			UnitBase::Render();
		}

		void BulletBase::Damage(int atk)
		{
			UnitBase::Damage(atk);
		}

		void BulletBase::Deleat()
		{
			exists = false;
		}

	}
}
