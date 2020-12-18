
#pragma once
#include "../../Include/Systems/PhysicsSystem.h"



PhysicsSystem::PhysicsSystem()
{

}

PhysicsSystem::~PhysicsSystem()
{
}


void threadPhysicsA()
{
	std::map<int, std::vector<PhysicsComponent> >& map = PhysicsSystem::getEntities();
	std::map<int, std::vector<PhysicsComponent> >::iterator it = map.begin();

	float deltaTime = 0;

	ge::Vector2f vec;

	int size = map.size();
	for (; it != map.end(); ++it)
	{

		int numberOfComponents = it->second.size();

		for (int i = 0; i < numberOfComponents; i++)
		{
			it->second.at(i).updatePosition(.10f);
			vec = it->second.at(i).position;
			SpriteSystem::getComponent(it->first).setPos(vec.x,vec.y);
		}

	}

}

void threadPhysicsB()
{
	std::map<int, std::vector<PhysicsComponent> >& map = PhysicsSystem::getEntities();
	std::map<int, std::vector<PhysicsComponent> >::reverse_iterator it = map.rbegin();

	float deltaTime = 0;

	ge::Vector2f vec;

	int size = PhysicsSystem::getEntities().size();
	int positiion = 0;
	for (; it != map.rend(); ++it)
	{
		positiion++;
		if (positiion == (size / 2) + 2)
		{
			break;
		}

		int numberOfComponents = it->second.size();

		for (int i = 0; i < numberOfComponents; i++)
		{
			it->second.at(i).updatePosition(.10f);
			vec = it->second.at(i).position;
			SpriteSystem::getComponent(it->first).setPosition(vec.x, vec.y);
		}

	}
}
void threadPhysicsC()
{
	std::map<int, std::vector<PhysicsComponent> >& map = PhysicsSystem::getEntities();
	std::map<int, std::vector<PhysicsComponent> >::iterator it = map.begin();

	float deltaTime = 0;

	ge::Vector2f vec;

	int size = PhysicsSystem::getEntities().size();
	for (; it != map.end(); ++it)
	{

		int numberOfComponents = it->second.size();

		for (int i = 0; i < numberOfComponents; i++)
		{
			it->second.at(i).updatePosition(.10f);
			vec = it->second.at(i).position;
			SpriteSystem::getComponent(it->first).setPosition(vec.x, vec.y);
		}

	}
}
void PhysicsSystem::update()
{
	int numberOfEntities = entities.size();
	std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		);

	std::thread a(threadPhysicsA);
	a.join();

	std::chrono::milliseconds after = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch());

	std::chrono::milliseconds diff = after - now;
	std::cout << "Physics " << std::to_string(numberOfEntities) << " components took: " << " " << diff.count() << "ns" << std::endl;

}

void PhysicsSystem::physicsUpdate()
{
	std::map<int, std::vector<PhysicsComponent> >& map = PhysicsSystem::getEntities();
	std::map<int, std::vector<PhysicsComponent> >::iterator it = map.begin();

	float deltaTime = 0;

	ge::Vector2f vec;

	int size = PhysicsSystem::getEntities().size();
	for (; it != map.end(); ++it)
	{

		int numberOfComponents = it->second.size();

		for (int i = 0; i < numberOfComponents; i++)
		{
			it->second.at(i).updatePosition(.10f);
			vec = it->second.at(i).position;
			SpriteSystem::getComponent(it->first).setPos(vec.x, vec.y);
		}

	}
}

void PhysicsSystem::threadA()
{
	std::thread a(threadPhysicsA);
	a.join();
}

void PhysicsSystem::threadB()
{
	std::thread b(threadPhysicsB);
	b.join();
}

