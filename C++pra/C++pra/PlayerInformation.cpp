#include "PlayerInformation.h"

namespace Unit
{
	namespace Player
	{
		PlayerInformation::PlayerInformation(PlayerController &player)
		{
			this->player = &player;
		}

		PlayerInformation::~PlayerInformation()
		{

		}

		D3DXVECTOR2 PlayerInformation::GetPosotion()
		{
			return player->GetPosition();
		}
	}
}