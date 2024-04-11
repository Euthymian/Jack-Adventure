#include "BSJump.h"

BSJump::BSJump(IBoss* boss)
{
	m_Boss = boss;
	m_ChangeStateTime = 3.f;
	m_CurrentTime = 0;
}

void BSJump::ibstateInit()
{
	m_Animation = new AnimationV2(*ResourceManager::getInstance()->getTexture("Boss1/jump"), sf::Vector2i(5, 4), 0.07, 17);
}

void BSJump::ibstateUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	m_Boss->getHitBox()->setPosition(m_Boss->getHitBox()->getPosition().x, ground - 88);
	m_Boss->getHitBox()->setHitBoxSize(sf::Vector2f(260, 200));

	if (m_Boss->getHitBox()->getPosition().x <= 90) {
		m_Boss->getHitBox()->move(80 * deltaTime, 0);
	}
	if (m_Boss->getHitBox()->getPosition().x >= 110) {
		m_Boss->getHitBox()->move(-80 * deltaTime, 0);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
	m_Animation->update(deltaTime);

	int repOfRandomState = rand() % 3;

	if (m_CurrentTime >= m_ChangeStateTime && ((AnimationV2*)m_Animation)->getCurrentNumOfFrames() == ((AnimationV2*)m_Animation)->getTotalFrame()) {
		switch (repOfRandomState)
		{
		case 0:
			break;
		case 1:
			m_Boss->changeNextState(JUMP_BITE);
			break;
		case 2:
			m_Boss->changeNextState(ATTACK);
			break;
		default:
			break;
		}
	}
}

void BSJump::ibstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSJump::stateReset()
{
	m_Animation->resetFrame();
	m_CurrentTime = 0;
}
