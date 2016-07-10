#pragma once
#include "../../Gizmos.h"
#include "../../glm/glm.hpp"

using namespace glm;


class Shape
{
public:
	int GetShapeType() { return static_cast<int>(m_id); }
	static int GetShapeCount() { return static_cast<int>(ShapeType::Count); }
	virtual void Draw(vec3 position) const = 0;

protected:
	enum ShapeType
	{
		Plane,
		Sphere,
		AABB,
		Count,
	};

	Shape(ShapeType id) : m_id(id) {}

private:
	ShapeType m_id;
};

