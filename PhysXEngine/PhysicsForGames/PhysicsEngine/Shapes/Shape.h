#pragma once
#include "../../Gizmos.h"

class Shape
{
public:
	Shape();
	~Shape();

	int GetShapeType();
	virtual void Draw(vec3 position);

protected:
	enum class ShapeType { Plane, Sphere, AABB };

private:
	ShapeType m_id;
};

