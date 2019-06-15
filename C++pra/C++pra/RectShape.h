#pragma once
#include "Shape.h"
namespace  Collision
{
	class RectShape : public Shape
	{
	public:
		RectShape(float left, float bottom, float right, float top) :
			m_left(left), m_bottom(bottom), m_right(right), m_top(top) {}
		~RectShape() {}


		ShapeType GetType();

		float GetLeft() { return m_left; }
		float GetBottom() { return m_bottom; }
		float GetRight() { return m_right; }
		float GetTop() { return m_top; }
	private:
		float m_left, m_bottom, m_right, m_top;
	};
}
