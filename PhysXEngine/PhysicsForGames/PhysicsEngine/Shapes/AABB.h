#pragma once
#include "Shape.h"

class AABB : public Shape
{
public:
	AABB(vec3 size) : 
		Shape(ShapeType::AABB), 
		m_size(size)
	{}

	vec3 GetSize() const { return m_size; }

	void Draw(vec3 position) override
	{
		Gizmos::addAABBFilled(position, m_size, vec4(0, 0.5, 0, 1));
	}

private:
	vec3 m_size;
};

