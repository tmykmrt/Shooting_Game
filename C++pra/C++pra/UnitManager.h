#pragma once
#include"stdafx.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "PlayerController.h"
#include "PlayerInformation.h"

class UnitManager : public Singleton<UnitManager>
{
public:
	friend class Singleton<UnitManager>;
	//!	“–‚½‚è”»’è
	void Colision();
	void Update();
	void Render();
	PlayerInformation &PlayerInfo();
protected:
	UnitManager();
	~UnitManager();
private:
	PlayerController *player;
	PlayerInformation *playerinfo;
};

