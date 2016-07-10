#pragma once
#include "Application.h"
#include "PhysicsEngine\PhysicsScene.h"
#include "Render.h"
#include "Camera.h"

#include <memory>
#include <random>

class PhysicsApplication : public Application
{
public:
	PhysicsApplication() :
		m_velocityDistribution(-20, 20),
		m_massDistribution(1, 10)
	{}

	virtual bool Startup();
	virtual void Shutdown();
	virtual bool Update();
	virtual void draw();

	std::unique_ptr<PhysicsScene> m_PhysicsScene;
	std::unique_ptr<Renderer> m_Renderer;
	FlyCamera m_Camera;

	// Spawning Physics Objects.
	float m_lastFrameTime;
	float m_spawnTimer;

	std::default_random_engine m_Generator;
	std::uniform_real_distribution<float> m_velocityDistribution;
	std::uniform_real_distribution<float> m_massDistribution;

private:
	void CreateBoundary(PhysicsScene* pPhysicsScene, float tableSize, float borderHeight);
	void CreateSpheres(PhysicsScene* pPhysicsScene, int sphereCount, float spacing);
	void CreateAABBs(PhysicsScene* pPhysicsScene, int aabbCount, float spacing);
};

