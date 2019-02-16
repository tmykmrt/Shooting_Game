#include "LimitPoint.h"
#include "GameUIManager.h"
#include "Input.h"

LimitPoint::LimitPoint()
{
	point.Set(0, 100, 0);
	point.Empty();
	isReleasing = false;
	GameUIManager::GetInstance()->UpdateMpBar(this->point.Rate());
}

LimitPoint::~LimitPoint()
{
}

void LimitPoint::Update()
{
	if (isReleasing == false) return;
	
	Add(-0.5);

	if (point.IsEmpty())
	{
		isReleasing = false;
	}
}

void LimitPoint::Recovery(float recovPoint = 10)
{
	Add(recovPoint);
}

void LimitPoint::Add(float point)
{
	this->point.Add(point);
	GameUIManager::GetInstance()->UpdateMpBar(this->point.Rate());
}

void LimitPoint::LimitReleasing()
{
	if (Input::GetInstance()->ChackKey(DIK_SPACE) == false) return;

	if (point.IsFull() == false) return;
	isReleasing = true;
}

