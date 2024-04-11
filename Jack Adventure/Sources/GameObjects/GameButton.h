#pragma once
#include <SFML/Graphics.hpp>
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"

class GameButton : public sf::RectangleShape {
public:
	GameButton();
	~GameButton();

	void bntInit(std::string name);
	void bntUpdate(float deltaTime);
	void bntRender(sf::RenderWindow* window);

	void handleTouchEvent();
	bool isHandle();

	void setOnClick(void (*Func)());
private:
	void (*m_bntClickFunc)();
	bool m_isHandling;
	static std::string m_Path;
};