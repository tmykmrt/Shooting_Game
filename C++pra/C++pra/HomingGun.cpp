#include "HomingGun.h"

using namespace Weapon;
using namespace Unit;
HomingGun::HomingGun(UnitBase &owner, D3DXVECTOR2 dirVec) : WeaponBase(owner, dirVec)
{
}

HomingGun::~HomingGun()
{
}
