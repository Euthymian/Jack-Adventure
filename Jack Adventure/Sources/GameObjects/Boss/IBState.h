#pragma once
#include "../../GameManager/ResourceManager.h"

class IBoss;

class IBState {
public:
	enum BSTATE {
		JUMP,
		JUMP_BITE,
		ATTACK,
		SNULL,
	};

	virtual void ibstateInit() = 0;
	virtual void ibstateUpdate(float deltaTime) = 0;
	virtual void ibstateRender(sf::RenderWindow* window) = 0;
	virtual void stateReset() = 0;

	virtual Animation* getAnimation() = 0;
};