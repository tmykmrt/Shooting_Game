#include "EnemyBase.h"
#include "MoveLeft.h"
EnemyBase::EnemyBase()
{
	
}

EnemyBase::EnemyBase(int moveType, D3DXVECTOR2 startPos)
{
	speed = 4;
	sprite.Load("Res/enemy_01.png", 128, 128);
	Init(moveType, startPos);
}

EnemyBase::~EnemyBase()
{
	delete mover;
	UnitBase::~UnitBase();
}

//
void EnemyBase::Init(int moveType, D3DXVECTOR2 startPos)
{
	this->moveType = moveType;
	position = startPos;
	exists = true;
	hp.Set(1);
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
	if (CheckScreenOut())
	{
		exists = false;
	}
}	//

void EnemyBase::Render()
{
	UnitBase::Render();
}

void EnemyBase::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}

