#pragma once
#include <memory>

#include "RigidBody.h"

#include "Shapes\Plane.h"
#include "Shapes\Sphere.h"
#include "Shapes\AABB.h"

using namespace glm;
using namespace std;

class PhysicsObject
{
public:
	PhysicsObject(vec3 _position, Shape* _shape, RigidBody* _rigidBody = nullptr) : m_position(_position), m_shape(_shape), m_rigidBody(_rigidBody)
	{}

	~PhysicsObject();

	void Update(vec3 _gravity, float _deltaTime) { if (m_rigidBody != nullptr) m_position += m_rigidBody->CalculatePositionDelta(_deltaTime, _gravity); }
	void DrawGizmos() { m_shape->Draw(m_position); }

	void AddPosition(vec3 positionDelta) { m_position += positionDelta; }
	void AddForce(vec3 force) { if (m_rigidBody != nullptr) m_rigidBody->AddForce(force); }
	void AddVelocity(vec3 velocity) { if (m_rigidBody != nullptr) m_rigidBody->AddVelocity(velocity); }
	void AddMomentum(vec3 momentum) { if (m_rigidBody != nullptr) m_rigidBody->AddMomentum(momentum); }

	float GetMass() const { return m_rigidBody == nullptr ? numeric_limits<float>::max() : m_rigidBody->GetMass(); }
	Shape* GetShape() const { return m_shape.get(); }
	vec3 GetVelocity() const { return m_rigidBody == nullptr ? vec3(0) : m_rigidBody->GetVelocity(); }
	vec3 GetMomentum() const { return GetMass() * GetVelocity(); }
	vec3 GetPosition() const { return m_position; }

private:
	vec3 m_position;
	std::unique_ptr<Shape> m_shape;
	std::unique_ptr<RigidBody> m_rigidBody;
};

