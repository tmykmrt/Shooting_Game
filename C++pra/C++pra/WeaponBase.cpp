#include "WeaponBase.h"
using namespace Unit;
WeaponBase::WeaponBase(UnitBase &owner, D3DXVECTOR2 dirVec)
	: owner(owner)
{
	this->dirVec = dirVec;
}

WeaponBase::~WeaponBase()
{
}

void WeaponBase::Update()
{
}
//	�V�����I�[�i�[�̓o�^
void WeaponBase::RegisterOwner(UnitBase &newOwner)
{
	owner = newOwner;
}