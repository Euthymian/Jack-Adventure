#pragma once
#include "../../GameManager/ResourceManager.h"

class IPState {
public:
	enum PSTATE {
		RUN,
		JUMP,
		FALL,
		DIE,
		ATTACK,
		SNULL,
	};

	virtual void ipstateInit() = 0;
	virtual void ipstateUpdate(float deltaTime) = 0;
	virtual void ipstateRender(sf::RenderWindow* window) = 0;
	virtual void stateReset() = 0;

	virtual Animation* getAnimation() = 0;
};