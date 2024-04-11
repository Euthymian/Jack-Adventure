#include "PSFall.h"

PSFall::PSFall(IPlayer* player)
{
	m_Player = player;
	m_CurrentTime = 0;
	m_acceleration = 9.8;
}

void PSFall::ipstateInit()
{
	m_Animation = new Animation(*ResourceManager::getInstance()->getTexture("Character/fall_down"), sf::Vector2i(8, 1), 0.1);
	m_Animation->setEndFrame(true);
}

void PSFall::ipstateUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	float currentYSpeed = 0 + m_acceleration * m_CurrentTime;
	if (m_Player->getHitBox()->getPosition().y <= ground) {
		//printf("%.2f   ", currentYSpeed / deltaTime);
		m_Player->getHitBox()->move(0, currentYSpeed);
	}
	else {
		m_Player->getHitBox()->setPosition(sf::Vector2f(m_Player->getHitBox()->getPosition().x, ground)    );
		m_CurrentTime = 0;
		m_Player->changeNextState(RUN);
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

void PSFall::ipstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFall::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}