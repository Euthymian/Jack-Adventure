#pragma once
#include "Layer.h"

class ParallelBackground {
public:
	void pbInit();
	void pbUpdate(float deltaTime);
	void pbRender(sf::RenderWindow* window);
private:
	std::list<Layer*> m_Background;
};