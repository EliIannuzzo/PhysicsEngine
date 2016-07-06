#pragma once
#include "../glm/glm.hpp"

class Plane;
class PhysicsObject;

using namespace glm;

class Collision
{
	Collision() = delete;
public:
	static bool Detect(PhysicsObject* _object1, PhysicsObject* _object2);

private:
	static bool PointToPlane(vec3 _point, const Plane* _plane);

	static bool PlaneToSphere(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool PlaneToAABB(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool PlaneToPlane(PhysicsObject* _object1, PhysicsObject* _object2);

	static bool SphereToPlane(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool SphereToSphere(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool SphereToAABB(PhysicsObject* _object1, PhysicsObject* _object2);

	static bool AABBToPlane(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool AABBToSphere(PhysicsObject* _object1, PhysicsObject* _object2);
	static bool AABBToAABB(PhysicsObject* _object1, PhysicsObject* _object2);

};

