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

		void SetGravity(vec3 _gravity);
		void RemoveActor(PhysicsObject* _actorToRemove);

		void AddPlaneStatic(glm::vec3 normal, float distance);
		void AddSphereStatic(glm::vec3 position, float radius);
		void AddAABBStatic(glm::vec3 position, glm::vec3 extents);

		void AddPlaneDynamic(glm::vec3 normal, float distance, float mass, glm::vec3 velocity);
		void AddSphereDynamic(glm::vec3 position, float radius, float mass, glm::vec3 velocity);
		void AddAABBDynamic(glm::vec3 position, glm::vec3 extents, float mass, glm::vec3 velocity);

private:
		void AddPlane(glm::vec3 normal, float distance, RigidBody* pRigidBody = nullptr);
		void AddSphere(glm::vec3 position, float radius, RigidBody* pRigidBody = nullptr);
		void AddAABB(glm::vec3 position, glm::vec3 extents, RigidBody* pRigidBody = nullptr);

	void AddActor(std::shared_ptr<PhysicsObject> pPhysicsObject);
	void CheckCollisions();

	vec3 m_gravity;
	float m_timestep = .001f;
	vector< std::shared_ptr<PhysicsObject> > m_actors;

};

