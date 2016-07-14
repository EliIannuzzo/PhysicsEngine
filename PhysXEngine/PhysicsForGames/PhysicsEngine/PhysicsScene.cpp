#include "PhysicsScene.h"
#include "RigidBody.h"
#include "PhysicsObject.h"
#include "Joints\SpringJoint.h"

void PhysicsScene::Update(float _deltaTime)
{
	const float DampingCoeffecient = 0.2f;

	for (auto& PysObj : m_actors)
	{
		PysObj->AddForce(DampingCoeffecient * -PysObj->GetVelocity() * _deltaTime);
	}

	for (auto& PysObj : m_actors)
	{
		PysObj->Update(m_gravity, _deltaTime);
	}

	CheckCollisions();
}

void PhysicsScene::AddGizmos()
{
	for (auto& PysObj : m_actors)
	{
		PysObj->DrawGizmos();
	}
}

shared_ptr<PhysicsObject> PhysicsScene::AddPlaneStatic(glm::vec3 normal, float distance)
{
	return AddPlane(normal, distance);
}

shared_ptr<PhysicsObject> PhysicsScene::AddSphereStatic(glm::vec3 position, float radius)
{
	return AddSphere(position, radius);
}

shared_ptr<PhysicsObject> PhysicsScene::AddAABBStatic(glm::vec3 position, glm::vec3 extents)
{
	return AddAABB(position, extents);
}

shared_ptr<PhysicsObject> PhysicsScene::AddPlaneDynamic(glm::vec3 normal, float distance, float mass, glm::vec3 velocity)
{
	return AddPlane(normal, distance, new RigidBody(mass, velocity));
}

shared_ptr<PhysicsObject> PhysicsScene::AddSphereDynamic(glm::vec3 position, float radius, float mass, glm::vec3 velocity)
{
	return AddSphere(position, radius, new RigidBody(mass, velocity));
}

shared_ptr<PhysicsObject> PhysicsScene::AddAABBDynamic(glm::vec3 position, glm::vec3 extents, float mass, glm::vec3 velocity)
{
	return AddAABB(position, extents, new RigidBody(mass, velocity));
}

shared_ptr<PhysicsObject> PhysicsScene::AddSpring(shared_ptr<PhysicsObject> connection1, shared_ptr<PhysicsObject> connection2, float springCoefficient, float damping, float restingDistance)
{
	auto pSpring = std::make_shared<SpringJoint>(connection1, connection2, springCoefficient, damping, restingDistance);
	AddActor(pSpring);
	return pSpring;
}

shared_ptr<PhysicsObject> PhysicsScene::AddPlane(glm::vec3 normal, float distance, RigidBody* pRigidBody)
{
	auto pPlane = std::make_shared<PhysicsObject>(
		glm::vec3(0),				// Position, not used for plane
		new Plane(normal, distance), // Normal and distance
		pRigidBody
		);
	AddActor(pPlane);
	return pPlane;
}

shared_ptr<PhysicsObject> PhysicsScene::AddSphere(glm::vec3 position, float radius, RigidBody* pRigidBody)
{
	auto pSphere = std::make_shared<PhysicsObject>(position, new Sphere(radius), pRigidBody);
	AddActor(pSphere);
	return pSphere;
}

shared_ptr<PhysicsObject> PhysicsScene::AddAABB(glm::vec3 position, glm::vec3 extents, RigidBody* pRigidBody)
{
	auto pBox = std::make_shared<PhysicsObject>(position, new AABB(extents), pRigidBody);
	AddActor(pBox);
	return pBox;
}

void PhysicsScene::AddActor(std::shared_ptr<PhysicsObject> pPhysicsObject)
{
	m_actors.push_back(pPhysicsObject);
}

void PhysicsScene::SetGravity(vec3 _gravity)
{
	m_gravity = _gravity;
}

void PhysicsScene::CheckCollisions()
{
	for (auto it1 = std::begin(m_actors); it1 != std::end(m_actors); it1++)
	{
		for (auto it2 = std::next(it1); it2 != std::end(m_actors); it2++)
		{
			Collision::Detect(it1->get(), it2->get());
		}
	}
}
