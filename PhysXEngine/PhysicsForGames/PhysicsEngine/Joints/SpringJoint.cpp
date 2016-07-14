#include "SpringJoint.h"

SpringJoint::SpringJoint(shared_ptr<PhysicsObject> connection1, shared_ptr<PhysicsObject> connection2, float springCoefficient, float damping, float restingDistance)
	: PhysicsObject(glm::vec3(0, 0, 0), nullptr, nullptr)
{
	m_connections[0] = connection1;
	m_connections[1] = connection2;

	m_springCoefficient = springCoefficient;
	m_damping = damping;
	if (restingDistance == 0)
		m_restLength = length(m_connections[0]->GetPosition() - m_connections[1]->GetPosition());
	else
		m_restLength = restingDistance;
}

void SpringJoint::Update(vec3 _gravity, float _timestep)
{
	vec3 offset = m_connections[0]->GetPosition() - m_connections[1]->GetPosition();
	vec3 direction = normalize(offset);
	float length = glm::length(offset);

	vec3 relativeVelocity = m_connections[0]->GetVelocity() - m_connections[1]->GetVelocity();
	vec3 force = -(m_springCoefficient * ((length - m_restLength) * direction)) - (m_damping * relativeVelocity);

	
	if (m_connections[0]->HasRigidbody())
	{
		m_connections[0]->AddForce(force);
	}
	
	if (m_connections[1]->HasRigidbody())
	{
		m_connections[1]->AddForce(-force);
	}
}

void SpringJoint::Debug()
{

}

void SpringJoint::DrawGizmos()
{
	Gizmos::addLine(m_connections[0]->GetPosition(), m_connections[1]->GetPosition(), vec4(1, 1, 1, 1));
}