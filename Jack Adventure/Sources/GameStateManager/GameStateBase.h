#pragma once
#include "../GameObjects/GameButton.h"
#include "GameStateMachine.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"
#include <iostream>

class GameStateBase {
public:
	GameStateBase() {};
	virtual ~GameStateBase() {};

	/*
	This is pure virtual method. It means there is a method called gsExit(),
	but it hasnt been initialized yet. Pure virtual methods usually appear inside
	superclass, now superclass is abstract class, its just be there but not real,
	so, we cant create a object with superclass is datatype.
	Derived classes have to override pure virtual methods unless they will become
	others abstract classes.
	*/

	virtual void gsExit() = 0;
	virtual void gsPause() = 0;
	virtual void gsResume() = 0;

	virtual void gsInit() = 0;
	virtual void gsUpdate(float deltaTime) = 0;
	virtual void gsRender(sf::RenderWindow* window) = 0;

	static GameStateBase* createState(GSTATE st);
};