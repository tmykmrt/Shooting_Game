#pragma once
#include "MovementBase.h"
class MoveLeft : public MovementBase
{
public:
	MoveLeft();
	~MoveLeft();
	void Move(D3DXVECTOR2 &vec);
};

