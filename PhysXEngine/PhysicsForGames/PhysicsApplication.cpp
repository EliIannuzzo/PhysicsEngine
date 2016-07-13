#include "PhysicsApplication.h"
#include "PhysicsEngine\PhysicsScene.h"
#include "PhysicsEngine\PhysicsObject.h"
#include "PhysicsEngine\RigidBody.h"

#include "PhysicsEngine\Shapes\Shape.h"
#include "PhysicsEngine\Shapes\Sphere.h"
#include "PhysicsEngine\Shapes\AABB.h"
#include "PhysicsEngine\Shapes\Plane.h"

#include "glm\glm.hpp"
#include "gl_core_4_4.h"
#include "GLFW\glfw3.h"
#include "Gizmos.h"

#include <functional>
#include <PxPhysicsAPI.h>

#define Assert(val) if (val){}else{ *((char*)0) = 0;}
#define ArrayCount(val) (sizeof(val)/sizeof(val[0]))

bool PhysicsApplication::Startup()
{
	if (Application::Startup() == false)
		return false;

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	Gizmos::create();

	m_Camera = FlyCamera(1280.0f / 720.0f, 10.0f);
	m_Camera.setLookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	m_Camera.sensitivity = 3;

	m_Renderer = std::make_unique<Renderer>();
	m_PhysicsScene = std::make_unique<PhysicsScene>(vec3(70, 0, 0));

	const float TableSize = 60;
	const float BorderHeight = 15;

	m_PhysicsScene->SetGravity(glm::vec3(0.0, -9.8, 0.0f));

	m_PhysicsScene->AddAABBStatic(vec3(0, 0, 0), vec3(1, 1, 1));
	m_PhysicsScene->AddSphereDynamic(vec3(0, 3, 0), 1, 5, vec3(0, 0, 0));

	m_lastFrameTime = (float)glfwGetTime();
	m_spawnTimer = 0;

	return true;

}

void PhysicsApplication::Shutdown()
{
	Gizmos::destroy();
	Application::Shutdown();
}

bool PhysicsApplication::Update()
{
	if (Application::Update() == false)
	{
		return false;
	}

	Gizmos::clear();

	float currentTime = (float)glfwGetTime();
	float deltaTime = currentTime - m_lastFrameTime;
	m_lastFrameTime = currentTime;

	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i <= 20; ++i)
	{
		Gizmos::addLine(vec3(-10 + i, -0.01, -10), vec3(-10 + i, -0.01, 10),
			i == 10 ? white : black);
		Gizmos::addLine(vec3(-10, -0.01, -10 + i), vec3(10, -0.01, -10 + i),
			i == 10 ? white : black);
	}

	m_Camera.update(deltaTime);
	m_PhysicsScene->Update(deltaTime);


	return true;
}

void PhysicsApplication::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_CULL_FACE);

	m_Renderer->RenderAndClear(m_Camera.view_proj);

	m_PhysicsScene->AddGizmos();

	Gizmos::draw(m_Camera.proj, m_Camera.view);

	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void PhysicsApplication::CreateBoundary(PhysicsScene* pPhysicsScene, float tableSize, float borderHeight)
{
	pPhysicsScene->AddAABBStatic(
		glm::vec3(0, 0.5f, (tableSize / 2) + 1),	// Position
		glm::vec3(tableSize / 2, borderHeight, 1)	// Extents
		);

	pPhysicsScene->AddAABBStatic(
		glm::vec3(0, 0.5f, (-tableSize / 2) - 1),		// Position
		glm::vec3(tableSize / 2, borderHeight, 1)	// Extents
		);

	pPhysicsScene->AddAABBStatic(
		glm::vec3((tableSize / 2) + 1, 0.5f, 0),		// Position
		glm::vec3(1, borderHeight, tableSize / 2)	// Extents
		);

	pPhysicsScene->AddAABBStatic(
		glm::vec3((-tableSize / 2) - 1, 0.5f, 0),		// Position
		glm::vec3(1, borderHeight, tableSize / 2)	// Extents
		);


}

void PhysicsApplication::CreateSpheres(PhysicsScene* pPhysicsScene, int sphereCount, float spacing)
{
	auto randVel = std::bind(m_velocityDistribution, m_Generator);

	for (int i = 0; i < sphereCount; i++) {
		float mass = m_massDistribution(m_Generator);
		pPhysicsScene->AddSphereDynamic(
			glm::vec3(-20 + i*spacing, 2 + i, -20 + i*spacing),		// Position
			std::pow(mass, 0.2f),								    // Radius
			mass,                                                   // Mass 
			glm::vec3(randVel(), 0, randVel())					    // Vel
			);
	}

}

void PhysicsApplication::CreateAABBs(PhysicsScene* pPhysicsScene, int aabbCount, float spacing)
{
	auto randVel = std::bind(m_velocityDistribution, m_Generator);
	for (int i = 0; i < aabbCount; i++) {
		pPhysicsScene->AddAABBDynamic(
			glm::vec3(-20 + i*spacing, 6 + i, -20 + i*spacing),	// Position
			glm::vec3(1, 1, 1),									// Extents
			1, glm::vec3(randVel(), 0, randVel())					// mass,vel
			);
	}

}
