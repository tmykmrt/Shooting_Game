#include "EnemyBase.h"
#include "UnitManager.h"
#include "MoveLeft.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::EnemyBase(int moveType, D3DXVECTOR2 startPos)
{
	speed = 4;
	shot = new EnemyShotTrigger(position);
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
	shot->Shot(UnitManager::GetInstance()->PlayerInfo().GetPosotion());
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