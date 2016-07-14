#pragma once
#include "Collision.h"
#include <vector>
#include <memory>

class Shape;
class RigidBody;
class PhysicsObject;

using namespace glm;
using namespace std;

class PhysicsScene
{
public:
	PhysicsScene() : PhysicsScene(glm::vec3(0)) {}
	PhysicsScene(glm::vec3 offset) : m_offset(offset) {}

	void Update(float _deltaTime);
	void AddGizmos();

		void SetGravity(vec3 _gravity);

		shared_ptr<PhysicsObject> AddPlaneStatic(glm::vec3 normal, float distance);
		shared_ptr<PhysicsObject> AddSphereStatic(glm::vec3 position, float radius);
		shared_ptr<PhysicsObject> AddAABBStatic(glm::vec3 position, glm::vec3 extents);

		shared_ptr<PhysicsObject> AddPlaneDynamic(glm::vec3 normal, float distance, float mass, glm::vec3 velocity);
		shared_ptr<PhysicsObject> AddSphereDynamic(glm::vec3 position, float radius, float mass, glm::vec3 velocity);
		shared_ptr<PhysicsObject> AddAABBDynamic(glm::vec3 position, glm::vec3 extents, float mass, glm::vec3 velocity);

		shared_ptr<PhysicsObject> AddSpring(shared_ptr<PhysicsObject> connection1, shared_ptr<PhysicsObject> connection2, float springCoefficient, float damping, float restingDistance = 0);

private:
		shared_ptr<PhysicsObject> AddPlane(glm::vec3 normal, float distance, RigidBody* pRigidBody = nullptr);
		shared_ptr<PhysicsObject> AddSphere(glm::vec3 position, float radius, RigidBody* pRigidBody = nullptr);
		shared_ptr<PhysicsObject> AddAABB(glm::vec3 position, glm::vec3 extents, RigidBody* pRigidBody = nullptr);

	void AddActor(std::shared_ptr<PhysicsObject> pPhysicsObject);
	void CheckCollisions();

	vec3 m_offset;
	vec3 m_gravity;
	float m_timestep = .001f;
	vector< std::shared_ptr<PhysicsObject> > m_actors;

};

