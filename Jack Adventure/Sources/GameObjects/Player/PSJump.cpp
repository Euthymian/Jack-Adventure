#include "PSJump.h"

PSJump::PSJump(IPlayer* player)
{
	m_Player = player;
	m_CurrentTime = 0;
	m_acceleration = 9.8;
}

void PSJump::ipstateInit()
{
	m_Animation = new Animation(*ResourceManager::getInstance()->getTexture("Character/jump_up"), sf::Vector2i(8, 1), 0.1);
	m_Animation->setEndFrame(true);
}

void PSJump::ipstateUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	float currentYSpeed = -m_Player->getHitBox()->getVelocity().y * deltaTime + m_acceleration * m_CurrentTime;
	if (currentYSpeed / deltaTime <= 0) {
		//printf("%.2f   ", currentYSpeed / deltaTime);
		m_Player->getHitBox()->move(0, currentYSpeed);
	}
	else {
		m_CurrentTime = 0;
		m_Player->changeNextState(FALL);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}

	if (!m_Player->getHitBox()->isAlive()) {
		m_Player->changeNextState(IPState::DIE);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->update(deltaTime);
}

void PSJump::ipstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSJump::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}