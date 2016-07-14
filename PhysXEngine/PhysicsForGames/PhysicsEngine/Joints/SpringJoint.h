#pragma once
#include "../PhysicsObject.h"

class SpringJoint : public PhysicsObject
{
public:
	SpringJoint(shared_ptr<PhysicsObject> connection1, shared_ptr<PhysicsObject> connection2, float springCoefficient, float damping, float restingDistance = 0);

private:
	void virtual Update(vec3 _gravity, float _timestep);
	void virtual Debug();
	void virtual DrawGizmos();

	shared_ptr<PhysicsObject> m_connections[2];
	float m_damping;
	float m_restLength;
	float m_springCoefficient;

};

