#include "Shape.h"
namespace Collision
{

	Shape::Shape()
	{
	}

	Shape::~Shape()
	{
	}

	void Shape::Clashed()
	{
		//parentUnit->Damage(1);
	}

	D3DXVECTOR2 Shape::GetPosition()
	{
		return position;
	}

	void Shape::SetPosition(D3DXVECTOR2 position)
	{ 
		this->position = position;
	}
}