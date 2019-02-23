#include "EnemyBase.h"
#include "UnitManager.h"
#include "MoveLeft.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::EnemyBase(int moveType, D3DXVECTOR2 startPos)
{
	speed = 4;
	trigger = new EnemyTrigger(this);
	sprite.Load("Res/enemy_01.png", 128, 128);
	Init(moveType, startPos);
}

EnemyBase::~EnemyBase()
{
	delete mover;
	UnitBase::~UnitBase();
}

void EnemyBase::Init(int moveType, D3DXVECTOR2 startPos)
{
	this->moveType = moveType;
	position = startPos;
	exists = true;
	dir = -1;
	hp.Set(1, 1, 0);

	if (moveType == 1)
	{
		mover = new MoveLeft();
		nowSpeed = speed;
	}
}

void EnemyBase::Update()
{
	mover->Move(vec);
	UpdatePosition();
	trigger->TriggerIfPossible();
	if (CheckScreenOut())
	{
		exists = false;
	}
}

void EnemyBase::Render()
{
	UnitBase::Render();
}

void EnemyBase::Damage(int atk)
{
	UnitBase::Damage(atk);
}