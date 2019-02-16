#include "PlayerInformation.h"

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
