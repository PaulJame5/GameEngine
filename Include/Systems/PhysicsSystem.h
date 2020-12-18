#pragma once
#include "../../Interfaces/I_ComponentSystem.h"
#include "../Components/PhysicsComponent.h"
#include "SpriteSystem.h"
#include "RenderingSystem.h"
#include <chrono>
#include <thread>



class PhysicsSystem : public I_ComponentSystem<PhysicsComponent>
{
public:
	PhysicsSystem();
	~PhysicsSystem();
	void update() override;
	void physicsUpdate();

	void threadA();
	void threadB();

private:
	SpriteSystem spriteSystem;
};


