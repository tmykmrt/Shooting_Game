#pragma once
#include"stdafx.h"
class PlayerBar;
class Sprite;

//	GameUI�̊Ǘ�
class GameUIManager : public Singleton<GameUIManager>
{
public:
	friend class Singleton<GameUIManager>;
	void Render();
protected:
	GameUIManager();
	~GameUIManager();
private:
	Sprite *powFlame;
	Sprite *pointFlame;
	PlayerBar *playerHp;
	PlayerBar *playerMp;
	PlayerBar *playerPow;
};

