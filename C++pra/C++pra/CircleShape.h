#pragma once
#include "Shape.h"

namespace  Collision 
{
	class CircleShape : public Shape
	{
	public:
		CircleShape(float radius);
		~CircleShape() {}
		ShapeType GetType();
		float GetX() { return GetPosition().x; }
		float GetY() { return GetPosition().y; }
		float GetRadius() const { return m_radius; }

	private:
		float m_radius;
	};
}
