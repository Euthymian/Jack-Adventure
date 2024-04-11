#include "Crow.h"

void Crow::creepInit()
{
	m_HitBox = new HitBox(sf::Vector2i(35, 30));
	//this->setStartPos(sf::Vector2f(screenWidth + 50, ground));
	m_HitBox->setPosition(m_StartPos);
	//m_HitBox->setVelocity(sf::Vector2f(150, 0));
	m_HitBox->setTag(CREEP);                                              

	m_MoveAni = new Animation(*ResourceManager::getInstance()->getTexture("PlagueCrow/walk"), sf::Vector2i(4, 1), 0.1);
	m_DieAni = new Animation(*ResourceManager::getInstance()->getTexture("PlagueCrow/die"), sf::Vector2i(5, 1), 0.1);
	m_CurrentAni = m_MoveAni;
}