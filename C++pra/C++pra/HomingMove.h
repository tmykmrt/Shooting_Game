#pragma once
#include "MovementBase.h"
class HomingMove :
	public MovementBase
{
public:
	HomingMove();
	~HomingMove();
	void Move(D3DXVECTOR2 &vec);
private:
	//D3DXVECTOR2 &target;
	
};

