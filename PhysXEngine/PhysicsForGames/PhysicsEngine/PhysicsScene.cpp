#include "PhysicsScene.h"
#include "RigidBody.h"
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene()
{
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::Update(float _deltaTime)
{
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

void PhysicsScene::SetGravity(vec3 _gravity)
{
	m_gravity = _gravity;
}

void PhysicsScene::CheckCollisions()
{

}
