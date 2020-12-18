///<summary>
/// Created by Paul O'Callaghan
/// GameEngine.h will have all the include files needed to get components and classes for use in your game.
/// The option is there for you to add in stuff as you need it but for simplicities sake you can just include this header file
/// Will need to include sfml in your project if your using sfml settings 
///</summary>
#pragma once

//void fixedUpdate();
//void renderUpdate(sf::RenderWindow& renderWindow);
//void threadA();
//void threadB();
//void threadPhysicsA();
//void threadPhysicsB();
//void threadPhysicsC();
#include "Systems/EngineSettings.h"
#include "Gizmos/Vector2.h"
#include "Gizmos/Entity.h"
#include "../Interfaces/I_ComponentSystem.h"
#include "Systems/RenderingSystem.h"
#include "SFML/Graphics.hpp"
#include "Game.h"

