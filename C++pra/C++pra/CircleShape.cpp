#include "CircleShape.h"
namespace Collision
{
	CircleShape::CircleShape(float radius) : m_radius(radius)
	{

	}

	ShapeType CircleShape::GetType()
	{
		return ShapeType::Circle;
	}

}