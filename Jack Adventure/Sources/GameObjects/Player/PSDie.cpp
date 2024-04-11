#include "PSDie.h"
#include "../../GameStateManager/GameStateMachine.h"

PSDie::PSDie(IPlayer* player)
{
	m_Player = player;
	m_CurrentTime = 0;
	m_ToNextStateTime = 2;
	m_Acceleration = 9.8;
}

void PSDie::ipstateInit()
{
	m_Animation = new Animation(*ResourceManager::getInstance()->getTexture("Character/die"), sf::Vector2i(12, 1), 0.1);
	m_Animation->setEndFrame(true);
}

void PSDie::ipstateUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	if (m_Player->getHitBox()->getPosition().y <= ground) {

		float currentYSpeed = 0 + m_Acceleration * m_CurrentTime;
		m_Player->getHitBox()->move(0, currentYSpeed);
	}
	
	if (m_CurrentTime >= m_ToNextStateTime) {
		GameStateMachine::getInstance()->changeState(END);
	}

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	m_Animation->update(deltaTime);
}

void PSDie::ipstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDie::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}