#pragma once
#include "Component.h"


class RenderComponent : public Component
{
public:
	RenderComponent();
	~RenderComponent();

	void setOrderInLayer(int orderInLayer);
	void draw();

private:
	int orderInLayer = 0;
};