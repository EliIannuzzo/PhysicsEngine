#include "RigidBody.h"

vec3 RigidBody::CalculatePositionDelta(float deltaTime, glm::vec3 gravity)
{
	glm::vec3 acceleration = m_force / m_mass;
	glm::vec3 oldVelocity = m_velocity;
	m_velocity += acceleration * deltaTime;
	m_velocity += gravity * deltaTime;

	// Midpoint method
	glm::vec3 positionDelta = (oldVelocity + m_velocity)*0.5f * deltaTime;

	m_force = glm::vec3(0);
	return positionDelta;
}