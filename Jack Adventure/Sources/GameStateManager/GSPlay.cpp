#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_Background = new ParallelBackground();
	m_Player = new Player();
	m_Boss = new Boss();
	m_Score = new sf::Text();

	m_CurrentTime = 0;
	m_CurrentScore = 0;
}

GSPlay::~GSPlay()
{
}

void GSPlay::gsExit()
{
}

void GSPlay::gsPause()
{
}

void GSPlay::gsResume()
{
}

void GSPlay::gsInit()
{
	printf("Play\n");
	m_Background->pbInit();

	m_Player->playerInit();
	m_CollisionMagager.addObj(m_Player->getHitBox());
	m_CreepManager.creepMngInit(m_CollisionMagager);
	m_Boss->bossInit(m_CollisionMagager);
	m_CollisionMagager.addObj(m_Boss->getHitBox());

	m_Score->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_Score->setString("0");
	m_Score->setPosition(50, 50);
	m_Score->setFillColor(sf::Color::Yellow);
}

void GSPlay::gsUpdate(float deltaTime)
{
	if (m_Player->getHitBox()->isAlive()) {
		m_CurrentTime += deltaTime;
		if (m_CurrentTime >= 0.5f) {
			m_CurrentScore++;
			m_Score->setString(std::to_string(m_CurrentScore));
			m_CurrentTime -= 0.5f;
		}
	}
	else ScoreManager::getInstance()->setCurrentScore(m_CurrentScore);
	m_Background->pbUpdate(deltaTime);
	m_Player->playerUpdate(deltaTime);
	m_CreepManager.creepMngUpdate(deltaTime);
	m_Boss->bossUpdate(deltaTime);
	m_CollisionMagager.collisionUpdate();
}

void GSPlay::gsRender(sf::RenderWindow* window)
{
	m_Background->pbRender(window);
	m_Player->playerRender(window);
	m_Boss->bossRender(window);
	m_CreepManager.creepMngRender(window);
	window->draw(*m_Score);
}
