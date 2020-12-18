#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SpriteComponent : public sf::Drawable, public sf::Transformable, public Component
{
public:
	SpriteComponent();
	SpriteComponent(std::string texturePath);
	SpriteComponent(const SpriteComponent& spriteComponent);
	~SpriteComponent();


	bool loadedTexture(std::string texturePath);
	void setPos(float x, float y);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;/*
	{
		std::cout << "drawing" << std::endl;
		target.draw(sprite);
	}*/

	sf::Texture m_texture;
	sf::Sprite sprite;
};
