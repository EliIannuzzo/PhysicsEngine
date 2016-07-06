#pragma once
#include "Collision.h"
#include <vector>

class Shape;
class RigidBody;
class PhysicsObject;

using namespace glm;
using namespace std;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void Update(float _deltaTime);
	void AddGizmos();

	void AddActor(PhysicsObject* _actorToAdd);
	void RemoveActor(PhysicsObject* _actorToRemove);

	void SetGravity(vec3 _gravity);
	

private:
	void CheckCollisions();

	vec3 m_gravity;
	float m_timestep = .001f;

	vector<PhysicsObject*> m_actors;

};

