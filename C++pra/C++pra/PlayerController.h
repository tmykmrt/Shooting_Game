#pragma once
#include "UnitBase.h"
#include "stdafx.h"
#include "Input.h"
#include "Animation2D.h"
#include "PlayerTrigger.h"
#include "LimitPoint.h"

class Animation2D;

namespace Unit
{
	namespace Player
	{
		class PlayerController : public UnitBase
		{
		public:
			PlayerController(TCHAR *name, int x, int y);
			~PlayerController();
			void Update();
			void Render();
			void CreateShape();
			void UpdateVecter();
			void Damage(int atk);
			void ChageLimit();
		private:
			//	
			D3DXVECTOR2 targetPosition;
			int animnum;
			Animation2D *anim;
			Animation2DData tmpD[2];
			LimitPoint *limitPoint;
			PlayerTrigger *trigger;
		};
	}
}
