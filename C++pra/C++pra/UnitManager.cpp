#include "UnitManager.h"
#include "Collision.h"
#include "PlayerController.h"
#include "BulletBase.h"
using namespace Unit::Bullet;
using namespace Unit::Enemy;
using namespace Unit::Player;
namespace Unit
{
	UnitManager::UnitManager()
	{
		Unit::Enemy::EnemyManager::CreateInstance();
		Unit::Bullet::BulletManager::CreateInstance();
		player = new Unit::Player::PlayerController("Res/player.png", 1280, 256);
		playerinfo = new Unit::Player::PlayerInformation(*player);
	}

	UnitManager::~UnitManager()
	{
		delete player;
		delete playerinfo;
		Unit::Enemy::EnemyManager::Destroy();
		Unit::Bullet::BulletManager::Destroy();
	}

	void UnitManager::Update()
	{
		player->Update();
		EnemyManager::GetInstance()->Update();
		Bullet::BulletManager::GetInstance()->Update();

		//	“–‚½‚è”»’è‚ÍŒ»Ý–³‚µ
		//	•Ê‚Ì‘‚«•û‚ª‚È‚¢‚©–Íõ’†
		//Colision();
	}

	void UnitManager::Render()
	{
		player->Render();
		Unit::Enemy::EnemyManager::GetInstance()->Render();
		Unit::Bullet::BulletManager::GetInstance()->Render();
	}

	void UnitManager::Colision()
	{

	}

	PlayerInformation &UnitManager::PlayerInfo()
	{
		return *playerinfo;
	}
}
