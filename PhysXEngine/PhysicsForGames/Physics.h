#ifndef SOUND_PROGRAMMING_H_
#define SOUND_PROGRAMMING_H_

#include "Application.h"
#include "Camera.h"
#include "Render.h"

#include <PxPhysicsAPI.h>
#include <PxScene.h>

class PhysicsScene;

using namespace physx;

class Physics : public Application
{
public:
	virtual bool startup();
	virtual void shutdown();
    virtual bool update();
    virtual void draw();

	void renderGizmos(PxScene* physics_scene);
	void SetupTutorial1();

	//PhysX
	void SetUpPhysX();
	void SetUpVisualDebugger();
	void UpdatePhysx(float);

	//Custom Physics
	void SetUpPhysics();

    Renderer* m_renderer;
    FlyCamera m_camera;
    float m_delta_time;

	PxFoundation* g_PhysicsFoundation;
	PxPhysics* g_Physics;
	PxScene* g_PhysicsScene;
	PxDefaultErrorCallback gDefaultErrorCallback;
	PxDefaultAllocator gDefaultAllocatorCallback;
	PxSimulationFilterShader gDefaultFilterShader = PxDefaultSimulationFilterShader;
	PxMaterial* g_PhysicsMaterial;
	PxMaterial* g_boxMaterial;
	PxCooking* g_PhysicsCooker;

	PhysicsScene* m_physicsScene;

};
#endif //CAM_PROJ_H_
