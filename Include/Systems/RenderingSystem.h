/*
	Created by Paul O'Callagahn 
	Rendering System is static due to the engine using a singleton pattern to keep only one existing of each object 
*/

#pragma once

#ifndef __RENDERINGSYSTEM_H__
#define __RENDERINGSYSTEM_H__

#include "SpriteSystem.h"
#include "../Components/PhysicsComponent.h"
#include "PhysicsSystem.h"
#include <map>
#include <vector>
#include <iostream>
#include <chrono>

class RenderingSystem
{
public:
	RenderingSystem();
	~RenderingSystem();

	void update(sf::RenderWindow& rend);

private:

//#if _DEBUG
	void TestBeginTime();
	void TestEndTime(); 
	
	std::chrono::milliseconds now;

	void drawSprites(sf::RenderWindow* rend);

	//to be implemented
	//void drawGUI();

//#endif

};
#endif