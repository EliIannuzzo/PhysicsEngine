#pragma once
#include "../glm/glm.hpp"
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

	void Update();
	void Draw();

	void AddPlaneStatic();
	void AddSphereStatic();
	void AddAABBStatic();

	void AddPlaneDynamic();
	void AddSphereDynamic();
	void AddAABBDynamic();

private:
	void AddPlane();
	void AddSphere();
	void AddAABB();

	void CheckCollisions();

	vec3 m_offset;
	vec3 m_gravity;
	vector <PhysicsObject> m_PhysicsObjects;

};

