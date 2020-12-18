#include "../../Include/Components/SpriteComponent.h"

SpriteComponent::SpriteComponent() 
{
	
}

SpriteComponent::SpriteComponent(std::string texturePath)
{
	if (!loadedTexture(texturePath))
	{
		std::cout << "Construction Error" << std::endl;
	}
}

SpriteComponent::SpriteComponent(const SpriteComponent& spriteComponent)
{
	m_texture = spriteComponent.m_texture;
	sprite = spriteComponent.sprite;
}

SpriteComponent::~SpriteComponent() 
{

}

bool SpriteComponent::loadedTexture(std::string texturePath)
{
	if (!m_texture.loadFromFile(texturePath))
	{
		std::cout << "Cannot find file: " << texturePath << std::endl;
		return false;
	}
	sprite.setTexture(m_texture);
	return true;
}

void SpriteComponent::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}




void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}