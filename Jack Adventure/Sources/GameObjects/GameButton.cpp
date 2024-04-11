#include "GameButton.h"

std::string GameButton::m_Path = "Button/";

GameButton::GameButton()
{
	m_isHandling = false;
}

GameButton::~GameButton()
{
}

void GameButton::bntInit(std::string name)
{
	this->setSize(sf::Vector2f(100, 100));
	this->setTexture(ResourceManager::getInstance()->getTexture(m_Path + name));
	this->setScale(0.8, 0.8);
	this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
}

void GameButton::bntUpdate(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		handleTouchEvent();
	}
}

void GameButton::bntRender(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::handleTouchEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WindowConnector::getInstance()->getWindow())))
	{
		m_bntClickFunc();
		m_isHandling = true;
	}
}

bool GameButton::isHandle()
{
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)())
{
	m_bntClickFunc = Func;
}
