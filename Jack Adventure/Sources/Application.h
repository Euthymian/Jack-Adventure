#pragma once
#include "GameManager/ResourceManager.h"

class Application {
public:
	void appRun();
	~Application();
private:
	void appInit();
	void appUpdate(float deltaTime);
	void appRender();
	sf::RenderWindow* m_window;
};