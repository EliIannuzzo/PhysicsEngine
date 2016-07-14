#pragma once
#include "Shape.h"

class Plane : public Shape
{
public:
	Plane(vec3 normal, float offset) : 
		Shape(ShapeType::Plane), 
		m_normal(normal), 
		m_offset(offset)
	{}

	vec3 GetNormal() const { return m_normal; }
	float GetDistance() const { return m_offset; }

	void Draw(vec3 position) const override
	{
		Gizmos::addAABBFilled(vec3(0, m_offset, 0), vec3(100.f, 0.01f, 100.f), vec4(0.25f, 0.25f, 0.25f, 1));
	}

private:
	vec3 m_normal;
	float m_offset; //distance
};

