#pragma once
#include <SFML/Graphics.hpp>
#include "../Singleton.h"

#define WConnect WindowConnector::getInstance()

class WindowConnector : public CSingleton <WindowConnector> {
public:
	WindowConnector();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
private:
	sf::RenderWindow* m_window;
};