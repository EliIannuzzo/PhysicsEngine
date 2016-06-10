#pragma once
#include "../glm/glm.hpp"

using namespace glm;

class RigidBody
{
public:
	RigidBody(float mass, vec3 initialVelocity) : m_mass(mass), m_velocity(initialVelocity)
	{}

	   float GetMass() const { return m_mass; }
	vec3 GetVelocity() const { return m_velocity; }
	vec3 GetMomentum() const { return GetMass() * GetVelocity(); }

	void Stop() { m_velocity = vec3(0); }
	void AddVelocity(vec3 velocity) { m_velocity += velocity; }
	void AddMomentum(vec3 momentum) { AddVelocity(momentum / m_mass); }
	void AddForce(vec3 force) { m_force += force; }

private:
	float m_mass;
	vec3 m_velocity;
	vec3 m_force;




};

