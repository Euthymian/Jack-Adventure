#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size)
	:RectangleShape((sf::Vector2f)size)
{
	this->setOrigin(sf::Vector2f(size / 2));
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineColor(sf::Color::Red);
	this-> setOutlineThickness(1);

	m_Velocity = sf::Vector2f(0, 0);

	m_IsAlive = true;
	m_IsUsed = true;
}

HitBox::~HitBox()
{
}

void HitBox::setVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

void HitBox::setHitBoxSize(sf::Vector2f size)
{
	this->setSize(size);
	this->setOrigin(size.x/2, size.y/2);
}

sf::Vector2f HitBox::getVelocity()
{
	return m_Velocity;
}
