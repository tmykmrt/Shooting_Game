#include "UnitBase.h"
#include "GameParameter.h"
#include "NumRange.h"

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
	return position;
}
