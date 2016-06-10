#include "PhysicsScene.h"
#include "RigidBody.h"
#include "PhysicsObject.h"

#include "Shapes\AABB.h"
#include "Shapes\Plane.h"
#include "Shapes\Sphere.h"


PhysicsScene::PhysicsScene()
{
	m_collision = new Collision();
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::Update(float _deltaTime)
{
	CheckCollisions();
	for (PhysicsObject* PysObj : m_actors)
	{
		PysObj->Update(m_gravity, _deltaTime);
	}
}

void PhysicsScene::AddGizmos()
{
	for (PhysicsObject* PysObj : m_actors)
	{
		PysObj->MakeGizmos();
	}
}

void PhysicsScene::AddActor(PhysicsObject* _actorToAdd)
{
	m_actors.push_back(_actorToAdd);
}

void PhysicsScene::RemoveActor(PhysicsObject* _actorToRemove)
{
	auto iter = std::find(m_actors.begin(), m_actors.end(), _actorToRemove);
	if (iter != m_actors.end())
	{
		m_actors.erase(iter);
	}
}

void PhysicsScene::CheckCollisions()
{
	m_collision
}
