#pragma once
#include"stdafx.h"
#include"PlayerController.h"
/**
* @file PlayerInformation.h
* @brief プレイヤー情報
* @date 2019 2/1
*/
namespace Unit
{
	namespace Player
	{
		class PlayerInformation
		{
		public:
			PlayerInformation(PlayerController &player);
			~PlayerInformation();
			//	座標を取得
			D3DXVECTOR2 GetPosotion();
		private:
			//	情報を監視するプレイヤー
			PlayerController *player;
		};
	}
}

