#pragma once
#include"UnitBase.h"
class UnitBase;
namespace Collision
{
	enum ShapeType
	{
		//	円
		Circle,
		//	箱
		Rect,
		Num,
	};

	/**
	* @brief 形状の基底クラス
	* @details  形状の基底クラス
	* @date 2019 2/26
	*/
	class Shape
	{
	public:
		Shape();
		~Shape();
		virtual ShapeType GetType() = 0;
		//	親ユニットの設定
		D3DXVECTOR2 GetPosition();
		void SetPosition(D3DXVECTOR2 position);
		void Clashed();
	private:
		D3DXVECTOR2 position;
		bool isHit;
	};
}