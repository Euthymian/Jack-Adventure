#include "BSJump_Bite.h"

BSJump_Bite::BSJump_Bite(IBoss* boss)
{
	m_Boss = boss;
	m_ChangeStateTime = 1.5f;
	m_CurrentTime = 0;
}

void BSJump_Bite::ibstateInit()
{
	m_Animation = new AnimationV2(*ResourceManager::getInstance()->getTexture("Boss1/jump_bite"), sf::Vector2i(5, 4), 0.07, 17);
}

void BSJump_Bite::ibstateUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	m_Boss->getHitBox()->setPosition(m_Boss->getHitBox()->getPosition().x, ground - 100);
	m_Boss->getHitBox()->setHitBoxSize(sf::Vector2f(260, 200));

	if (m_Boss->getHitBox()->getPosition().x <= 260) {
		m_Boss->getHitBox()->move(200 * deltaTime, 0);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
	m_Animation->update(deltaTime);

	int repOfRandomState = rand() % 2;

	if (m_CurrentTime >= m_ChangeStateTime && ((AnimationV2*)m_Animation)->getCurrentNumOfFrames() == ((AnimationV2*)m_Animation)->getTotalFrame()) {
		switch (repOfRandomState)
		{
		case 0:
			m_Boss->changeNextState(ATTACK);
			break;
		case 1:
			m_Boss->changeNextState(JUMP);
			break;
		default:
			break;
		}
	}
}

void BSJump_Bite::ibstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSJump_Bite::stateReset()
{
	m_CurrentTime = 0;
	m_Animation->resetFrame();
}
