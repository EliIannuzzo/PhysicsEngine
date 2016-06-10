#pragma once
#include "../glm/glm.hpp"
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
	

private:
	void CheckCollisions();

	vec3 m_gravity;
	float m_timestep = 0;

	vector <PhysicsObject*> m_actors;
	Collision* m_collision;

};

