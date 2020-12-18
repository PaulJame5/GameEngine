#pragma once
#include "../Gizmos/Vector2.h"



class PhysicsComponent : public Component
{
public:
	PhysicsComponent();
	~PhysicsComponent();

	void initialiseRandomVelocitiy();
	ge::Vector2f position;
	ge::Vector2f velocity;

	void updatePosition(float deltaTime);
private:

};

inline PhysicsComponent::PhysicsComponent()
{
	int x = std::rand() % 500 + 50;
	int y = std::rand() % 500 + 50;
	position = ge::Vector2f(x, y);
}

inline PhysicsComponent::~PhysicsComponent()
{
}

inline void PhysicsComponent::initialiseRandomVelocitiy()
{
	velocity.x =  std::rand() % 10 - 10 + 5;
	velocity.y =  std::rand() % 10 - 10 + 5;
	
}

inline void PhysicsComponent::updatePosition(float deltaTime)
{
	position += velocity * deltaTime;

	// keep to bounds
	if (position.x < -5)
	{
		position.x = 600;
		return;
	}

	if (position.y < -5)
	{
		position.y = 600;
		return;
	}
	
	if (position.x > 600)
	{
		position.x = -5;
		return;
	}

	if (position.y > 600)
	{
		position.y = -5;
	}
}
