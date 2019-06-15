#include "UnitBase.h"
#include "GameParameter.h"
#include "NumRange.h"
#include "Shape.h"

namespace Unit
{
	UnitBase::UnitBase()
	{

	}

	UnitBase::~UnitBase()
	{
		sprite.Release();
	}

	void UnitBase::Render()
	{
		sprite.pos = position;
		sprite.DrawCenter();
	}

	bool UnitBase::Exists() { return exists; }

	bool UnitBase::CheckScreenOut()
	{
		if (position.x > SCREEN_WIDTH
			|| position.x < 0
			|| position.y > SCREEN_HEIGHT
			|| position.y < 0)
		{
			return true;
		}
		return false;
	}

	void UnitBase::UpdatePosition()
	{
		position += vec * nowSpeed;
		shape->SetPosition(position);
	}

	void UnitBase::Damage(int atk)
	{
		hp.Add(-atk);
		if (hp.IsEmpty())
		{
			exists = false;
		}
	}

	D3DXVECTOR2 UnitBase::GetPosition()
	{
		if (position == nullptr) return D3DXVECTOR3(0.0, 0.0, 0.0);
		return position;
	}

	//	目標を設定する
	void UnitBase::SetAttackTarget()
	{

	}

	AttackUseInfo UnitBase::FetchAttackUseInfo()
	{
		AttackUseInfo retinfo;
		retinfo.dir = dir;
		retinfo.attckPosition = position;
		retinfo.targetPosition = position;
		retinfo.ownerType = myType;
		return retinfo;
	}
}
