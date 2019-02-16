#pragma once
#include"stdafx.h"
class PlayerBar;
class Sprite;

//	GameUIÇÃä«óù
class GameUIManager : public Singleton<GameUIManager>
{
public:
	friend class Singleton<GameUIManager>;
	void Update();
	void Render();
	void UpdateHpBar(float raito);
	void UpdateMpBar(float raito);
	void UpdatePowBar(float raito);
protected:
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

