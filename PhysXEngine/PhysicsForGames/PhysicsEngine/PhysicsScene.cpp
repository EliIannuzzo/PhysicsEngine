#include "PhysicsScene.h"
#include "RigidBody.h"
#include "PhysicsObject.h"

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

void PhysicsScene::AddPlaneStatic(glm::vec3 normal, float distance)
{
	AddPlane(normal, distance);
}

void PhysicsScene::AddSphereStatic(glm::vec3 position, float radius)
{
	AddSphere(position, radius);
}

void PhysicsScene::AddAABBStatic(glm::vec3 position, glm::vec3 extents)
{
	AddAABB(position, extents);
}

void PhysicsScene::AddPlaneDynamic(glm::vec3 normal, float distance, float mass, glm::vec3 velocity)
{
	AddPlane(normal, distance, new RigidBody(mass, velocity));
}

void PhysicsScene::AddSphereDynamic(glm::vec3 position, float radius, float mass, glm::vec3 velocity)
{
	AddSphere(position, radius, new RigidBody(mass, velocity));
}

void PhysicsScene::AddAABBDynamic(glm::vec3 position, glm::vec3 extents, float mass, glm::vec3 velocity)
{
	AddAABB(position, extents, new RigidBody(mass, velocity));
}

void PhysicsScene::AddPlane(glm::vec3 normal, float distance, RigidBody* pRigidBody)
{
	auto pPlane = std::make_shared<PhysicsObject>(
		glm::vec3(0),				// Position, not used for plane
		new Plane(normal, distance), // Normal and distance
		pRigidBody
		);
	AddActor(pPlane);
}

void PhysicsScene::AddSphere(glm::vec3 position, float radius, RigidBody* pRigidBody)
{
	auto pSphere = std::make_shared<PhysicsObject>(position, new Sphere(radius), pRigidBody);
	AddActor(pSphere);
}

void PhysicsScene::AddAABB(glm::vec3 position, glm::vec3 extents, RigidBody* pRigidBody)
{
	auto pBox = std::make_shared<PhysicsObject>(position, new AABB(extents), pRigidBody);
	AddActor(pBox);
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
