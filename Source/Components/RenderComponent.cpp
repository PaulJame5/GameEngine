#pragma once
#include "../../Include/Components/RenderComponent.h"
#include <iostream>


RenderComponent::RenderComponent()
{
	orderInLayer = 0;
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::setOrderInLayer(int orderInLayer)
{
	this->orderInLayer = orderInLayer;
}

void RenderComponent::draw()
{
	std::cout << "drawing object on layer: " << orderInLayer << std::endl;
}



