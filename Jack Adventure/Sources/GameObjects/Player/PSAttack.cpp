#include "PSAttack.h"

PSAttack::PSAttack(IPlayer* player)
{
	m_Player = player;
	m_CurrentTime = 0;
}

void PSAttack::ipstateInit()
{
	m_Animation = new Animation(*ResourceManager::getInstance()->getTexture("Character/attack"), sf::Vector2i(8, 1), 0.1);
}

void PSAttack::ipstateUpdate(float deltaTime)
{
	m_Player->getHitBox()->setAlive(true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_Player->changeNextState(RUN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_Player->changeNextState(JUMP);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->update(deltaTime);
}

void PSAttack::ipstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSAttack::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}