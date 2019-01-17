#pragma once
#include"stdafx.h"

class ShotPower;

class ShotBase
{
public:
	ShotBase();
	~ShotBase();
	void Shot(D3DXVECTOR2 shotPosition);
private:
	ShotPower *power;
};

