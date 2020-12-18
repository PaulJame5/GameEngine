#pragma once
#include "../../Include/Components/SpriteComponent.h"
#include "../../Interfaces/I_ComponentSystem.h"

class SpriteSystem : public I_ComponentSystem<SpriteComponent>
{
public:
	SpriteSystem();
	~SpriteSystem() override;


	void update() override;
};