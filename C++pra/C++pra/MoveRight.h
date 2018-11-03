#pragma once
#include "MovementBase.h"
/**
* @file MoveRight.h
* @brief 右に移動クラス
* @date 2018 11/03
*/
class MoveRight :
	public MovementBase
{
public:
	MoveRight();
	~MoveRight();

	void Move(D3DXVECTOR2 &vec);
};

