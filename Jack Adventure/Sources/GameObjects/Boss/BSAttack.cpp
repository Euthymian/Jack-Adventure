#include "BSAttack.h"

BSAttack::BSAttack(IBoss* boss)
{
	m_Boss = boss;
	m_ChangeStateTime = 3.f;
	m_CurrentTime = 0;
}

void BSAttack::ibstateInit()
{
	m_Animation = new AnimationV2(*ResourceManager::getInstance()->getTexture("Boss1/attack"), sf::Vector2i(4, 4), 0.07, 15);
}

void BSAttack::ibstateUpdate(float deltaTime)
{
	m_Boss->getHitBox()->setPosition(m_Boss->getHitBox()->getPosition().x, ground - 50);
	m_Boss->getHitBox()->setHitBoxSize(sf::Vector2f(180, 110));
	m_Boss->getHitBox()->move(-80 * deltaTime, 0);
	if (m_Boss->getHitBox()->getPosition().x <= -30) {
		if (rand() % 2) m_Boss->changeNextState(JUMP);
		else m_Boss->changeNextState(JUMP_BITE);
	}

	if (m_Animation->getCurrentFrame().x == 3 && m_Animation->getCurrentFrame().y == 0) {
		setFireStatus(true);
	}

	if (m_Animation->getCurrentFrame().x == 3 && m_Animation->getCurrentFrame().y == 2 && getFireStatus()) {
		setFireStatus(false);
		m_Boss->getBulletManager()->Fire(sf::Vector2f(m_Boss->getHitBox()->getPosition().x + 110, ground - 10));
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
	m_Animation->update(deltaTime);
}

void BSAttack::ibstateRender(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSAttack::stateReset()
{
	m_Animation->resetFrame();
	m_CurrentTime = 0;
}
