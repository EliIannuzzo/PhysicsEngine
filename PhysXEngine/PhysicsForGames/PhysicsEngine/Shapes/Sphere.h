#pragma once
#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(float radius) : 
		Shape(ShapeType::Sphere), 
		m_radius(radius)
	{}

	float GetRadius() const { return m_radius; }

	void Draw(vec3 position) const override 
	{
		Gizmos::addSphereFilled(position, m_radius, 10, 10, vec4(0.5f, 0, 0, 1));
	}

private:
	float m_radius;
};

