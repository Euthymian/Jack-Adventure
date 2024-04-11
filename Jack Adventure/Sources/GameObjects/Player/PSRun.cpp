#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_Player = player;
	m_CurrentTime = 0;
}

void PSRun::ipstateInit()
{
	m_Animation = new Animation(*ResourceManager::getInstance()->getTexture("Character/run"),sf::Vector2i(8,1),0.1);
}

void PSRun::ipstateUpdate(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		m_Player->changeNextState(JUMP);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		m_Player->changeNextState(ATTACK);
	}

	if (!m_Player->getHitBox()->isAlive()) { 
		m_Player->changeNextState(IPState::DIE); 
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->update(deltaTime);
}

void PSRun::ipstateRender(sf::RenderWindow* window)
{
	window->draw(* m_Animation);
}

void PSRun::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}