#pragma once
#include"stdafx.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "PlayerController.h"
#include "PlayerInformation.h"

namespace Unit
{
	class UnitManager : public Singleton<UnitManager>
	{
	public:
		friend class Singleton<UnitManager>;
		//!	“–‚½‚è”»’è
		void Colision();
		void Update();
		void Render();
		void CreateShape();
		Player::PlayerInformation &PlayerInfo();
	protected:
		UnitManager();
		~UnitManager();
	private:
		Player::PlayerController *player;
		Player::PlayerInformation *playerinfo;
	};
}

