#pragma once
#include"stdafx.h"
#include"PlayerController.h"
/**
* @file PlayerInformation.h
* @brief �v���C���[���
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
			//	���W���擾
			D3DXVECTOR2 GetPosotion();
		private:
			//	�����Ď�����v���C���[
			PlayerController *player;
		};
	}
}

