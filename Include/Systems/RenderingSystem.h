/*
	Created by Paul O'Callagahn 
	Rendering System is static due to the engine using a singleton pattern to keep only one existing of each object 
*/

#pragma once

#ifndef __RENDERINGSYSTEM_H__
#define __RENDERINGSYSTEM_H__

#include "../Components/RenderComponent.h"
#include <map>
#include <vector>
#include "../../Interfaces/I_ComponentSystem.h"
#include <iostream>

class RenderingSystem : public I_ComponentSystem<RenderComponent>
{
public:
	RenderingSystem();
	~RenderingSystem() override;

	
	void update() override;



	/*static void addComponent(int entityId);
	static void removeComponent(int entityId);
	static bool hasComponent(int entityId);
	static RenderComponent getComponent(int entityId);
	static void update();*/

};
#endif

inline RenderingSystem::RenderingSystem()
{

}

inline RenderingSystem::~RenderingSystem()
{
	entities.clear();
}

inline void RenderingSystem::update()
{

	std::map<int, std::vector<RenderComponent> >::iterator it = entities.begin();
	
	for (; it != entities.end(); ++it)
	{
		int size = it->second.size();
		for (int i = 0; i < size; i++)
		{
			std::cout << "Drawing Entity With Id: " << it->first << ", Renderer Component: " << i << std::endl;
		}
	}
}


