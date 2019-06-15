#pragma once
#include"UnitBase.h"
class UnitBase;
namespace Collision
{
	enum ShapeType
	{
		//	�~
		Circle,
		//	��
		Rect,
		Num,
	};

	/**
	* @brief �`��̊��N���X
	* @details  �`��̊��N���X
	* @date 2019 2/26
	*/
	class Shape
	{
	public:
		Shape();
		~Shape();
		virtual ShapeType GetType() = 0;
		//	�e���j�b�g�̐ݒ�
		D3DXVECTOR2 GetPosition();
		void SetPosition(D3DXVECTOR2 position);
		void Clashed();
	private:
		D3DXVECTOR2 position;
		bool isHit;
	};
}