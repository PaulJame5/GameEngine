/*
	Created by Paul O'Callaghan
	Handles the game loop
*/
#pragma once
#include "../Include/Systems/EngineSettings.h"
#include "Systems/RenderingSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Components/PhysicsComponent.h"
#include "../RenderEngine/Window.h"
#include "Gizmos/Entity.h"
#include <iostream>

#ifdef SFML
#include <SFML/Graphics.hpp>
#endif




class Game
{
public:
	Game();
	~Game();
	sf::RenderWindow gameWindow;
	void run();

	static bool applicationOpen;

private:
};

inline Game::Game() {}
inline Game::~Game() {}


// will run at a fixed interval whether update can keep up or not
inline void fixedUpdate()
{
	PhysicsSystem phys;
	while (Game::applicationOpen)
	{

		phys.update();
	}
	std::cout << "Fixed Update Finished" << std::endl;
}

// will aim for 60fps
inline void update()
{

}


// will run as fast as possible
inline void renderUpdate(sf::RenderWindow& gameWindow)
{
	Game::applicationOpen = false;
}

inline void Game::run()
{
	gameWindow.close();
	gameWindow.create(sf::VideoMode(600, 600), "Game");
	applicationOpen = true;

	RenderingSystem renderSytem;

	// begin fixed update loop
	std::thread updateLoop(fixedUpdate);

	

	gameWindow.setFramerateLimit(60);

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				applicationOpen = false;
				gameWindow.close();
			}
		}
		gameWindow.clear();
		renderSytem.update(gameWindow);
		gameWindow.display();
	}
	updateLoop.join();
}

