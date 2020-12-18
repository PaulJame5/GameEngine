/*
	Created by Paul O'Callaghan
	An Abstracted Windowing class for easier integration when the engine has backend updates
*/
#pragma once
#include "../Include/Systems/EngineSettings.h"
#include <string>

//====== Define in Engine Settings DO NOT DEFINE HERE ===========//
#ifdef SFML
#include <SFML/Graphics.hpp>
#endif // SFML
#ifdef SDL
//include SDL here
#endif // SDL






class Window
{
public:
	Window();
	Window(int width, int height, std::string windowName);
	~Window();

	void clear();
	void display();

#ifdef SFML
	sf::CircleShape circleShape;
	int width = 800;
	int height = 600;
	//sf::RenderWindow& renderWindow;
#endif // SFML
private:
	void initialise(int width, int height, std::string windowName);

};