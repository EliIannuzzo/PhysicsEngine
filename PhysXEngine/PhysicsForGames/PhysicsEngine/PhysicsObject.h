#pragma once
#include "../glm/glm.hpp"
#include "RigidBody.h"

#include "Shapes\Shape.h"
#include "Shapes\Plane.h"
#include "Shapes\Sphere.h"
#include "Shapes\AABB.h"

using namespace glm;

class PhysicsObject
{
public:
	PhysicsObject();
	~PhysicsObject();

	void Update();
	void Draw();

	void AddForce();
	void AddVelocity();
	void AddMomentum();

	vec3 GetVelocity();
	vec3 GetMomentum();
	vec3 GetPosition();
	Shape* GetShape();

private:
	vec3 m_position;
	Shape m_sphere;
	RigidBody m_rigidBody;

};

