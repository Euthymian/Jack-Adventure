#include "Bat.h"

void Bat::creepInit()
{
	m_HitBox = new HitBox(sf::Vector2i(27, 20));
	//this->setStartPos(sf::Vector2f(screenWidth + 50, screenHeight * 2 / 5));
	m_HitBox->setPosition(m_StartPos);
	//m_HitBox->setVelocity(sf::Vector2f(250 , 0));
	m_HitBox->setTag(CREEP);

	m_MoveAni = new Animation(*ResourceManager::getInstance()->getTexture("Bat/fly"), sf::Vector2i(6, 1), 0.1);
	m_DieAni = new Animation(*ResourceManager::getInstance()->getTexture("Bat/die"), sf::Vector2i(8, 1), 0.1);
	m_CurrentAni = m_MoveAni;
}
