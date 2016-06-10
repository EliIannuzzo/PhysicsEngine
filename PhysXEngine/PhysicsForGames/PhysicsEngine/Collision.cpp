#include "Collision.h"
#include "PhysicsObject.h"
#include "Shapes\Sphere.h"
#include "Shapes\AABB.h"
#include "Shapes\Plane.h"

bool Collision::Detect(PhysicsObject* _object1, PhysicsObject* _object2)
{
	int shape1_ID = _object1->GetShape()->GetShapeType();
	int shape2_ID = _object2->GetShape()->GetShapeType();
	
	//Math to calculate the currect collision function(https://github.com/johnsietsma).
	int collisionFunctionIndex = shape1_ID * Shape::GetShapeCount() + shape2_ID;

	switch (collisionFunctionIndex)
	{
	case 0:
		PlaneToSphere(_object1, _object2);
		break;
	case 1:
		PlaneToAABB(_object1, _object2);
		break;
	case 2:
		PlaneToPlane(_object1, _object2);
		break;
	case 3:
		SphereToPlane(_object1, _object2);
		break;
	case 4:
		SphereToSphere(_object1, _object2);
		break;
	case 5:
		SphereToAABB(_object1, _object2);
		break;
	case 6:
		AABBToPlane(_object1, _object2);
		break;
	case 7:
		AABBToSphere(_object1, _object2);
		break;
	case 8:
		AABBToAABB(_object1, _object2);
		break;
	default:
		break;
	}
}

// ----- Point collisions -----
bool Collision::PointToPlane(vec3 _point, const Plane* _plane)
{
	return dot(_point, _plane->GetNormal()) < 0;
}


// ----- Plane collisions -----
bool Collision::PlaneToSphere(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::PlaneToAABB(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::PlaneToPlane(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

// ----- Sphere collisions -----
bool Collision::SphereToPlane(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::SphereToSphere(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::SphereToAABB(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

// ----- AABB collisions -----
bool Collision::AABBToPlane(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::AABBToSphere(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

bool Collision::AABBToAABB(PhysicsObject* _object1, PhysicsObject* _object2)
{

}

void Collision::Seperate(PhysicsObject* _object1, PhysicsObject* _object2, float overlap, vec3 normal)
{

}

void Collision::Respond(PhysicsObject* _object1, PhysicsObject* _object2, float overlap, vec3 normal)
{

}