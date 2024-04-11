#include "Layer.h"

void Layer::layerInit(std::string name, float speed)
{
	m_Speed = speed;
	m_TextureLayer = ResourceManager::getInstance()->getTexture(name);
	m_Image1.setTexture(*m_TextureLayer);
	m_Image2.setTexture(*m_TextureLayer);
	if (m_Speed < 0) {
		m_Image1.setPosition(0, int(screenHeight - m_TextureLayer->getSize().y));
		m_Image2.setPosition(screenWidth - 1, int(screenHeight - m_TextureLayer->getSize().y));
	}
	else {
		m_Image1.setPosition(-screenWidth + 1, int(screenHeight - m_TextureLayer->getSize().y));
		m_Image2.setPosition(0, int(screenHeight - m_TextureLayer->getSize().y));
	}
}

void Layer::layerUpdate(float deltaTime)
{
	if (m_Speed < 0) {
		if (m_Image2.getPosition().x <= 0) {
			m_Image1.setPosition(0, int(screenHeight - m_TextureLayer->getSize().y));
			m_Image2.setPosition(screenWidth - 1, int(screenHeight - m_TextureLayer->getSize().y));
		}
	}
	else {
		if (m_Image2.getPosition().x >= screenWidth) {
			m_Image1.setPosition(-screenWidth + 1, int(screenHeight - m_TextureLayer->getSize().y));
			m_Image2.setPosition(0, int(screenHeight - m_TextureLayer->getSize().y));
		}
	}
	m_Image1.move(m_Speed * deltaTime, 0);
	m_Image2.move(m_Speed * deltaTime, 0);
}

void Layer::layerRender(sf::RenderWindow* window)
{
	window->draw(m_Image1);
	window->draw(m_Image2);
}


