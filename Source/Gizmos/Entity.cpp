#include "../../Include/Gizmos/Entity.h"
#include  <iostream>
#include <type_traits>

ge::Entity::Entity()
{
	name = " ";
	if (reusableIds.size() == 0)
	{
		id = currentAssignableId++;
		return;
	}
	id = reusableIds.front();
	reusableIds.pop();

}

ge::Entity::Entity(std::string name)
{
	this->name = name;
	if (reusableIds.size() == 0)
	{
		id = currentAssignableId++;
		return;
	}
	id = reusableIds.front();
	reusableIds.pop();
}

ge::Entity::~Entity()
{
	/*reusableIds.push(id);*/
}
int ge::Entity::getId()
{
	return id;
}

std::string ge::Entity::getName()
{
	return name;
}

void ge::Entity::setName(std::string name)
{
	this->name = name;
}
void ge::Entity::clearReusableIds()
{
	while (!reusableIds.empty())
	{
		reusableIds.pop();
	}
}

int ge::Entity::currentAssignableId = 0;
std::queue<int> ge::Entity::reusableIds = std::queue<int>();