#include "Bullet.h"
#include "../Boss/Boss.h"

Bullet::Bullet()
{
	m_DisappearTime = 0.5;
	m_CurrentTime = 0;
}

Bullet::~Bullet()
{
	m_CurrentAni = nullptr;
	if (m_MoveAni != nullptr) {
		delete m_MoveAni;
		m_MoveAni = nullptr;
	}
	if (m_ImpactAni != nullptr) {
		delete m_ImpactAni;
		m_ImpactAni = nullptr;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
		m_HitBox = nullptr;
	}
}

void Bullet::bulletInit()
{
	m_HitBox = new HitBox(sf::Vector2i(50, 12));
	m_HitBox->setVelocity(sf::Vector2f(250 , 0));
	m_HitBox->setTag(BOSS_BULLET);

	m_MoveAni = new AnimationV2(*ResourceManager::getInstance()->getTexture("Boss1/bullet"), sf::Vector2i(4, 3), 0.1, 12);
	m_MoveAni->setScale(-1, 1); //flip origin animation horizontally
	m_ImpactAni = new AnimationV2(*ResourceManager::getInstance()->getTexture("Boss1/impact"), sf::Vector2i(4, 3), 0.04, 12);
	m_ImpactAni->setScale(-1, 1);
	m_CurrentAni = m_MoveAni;
}

void Bullet::bulletUpdate(float deltaTime)
{
	if (m_HitBox->isUsed()) {
		if (m_HitBox->isAlive()) m_HitBox->move(m_HitBox->getVelocity().x * deltaTime, 0);
		else {
			m_CurrentTime += deltaTime;
			m_CurrentAni = m_ImpactAni;
			m_CurrentAni->setEndFrame(true);
			if (m_CurrentTime >= m_DisappearTime) {
				m_HitBox->setUsed(false);
			}
		}
		if (m_HitBox->getPosition().x >= screenWidth + 50) {
			m_HitBox->setAlive(false);
			m_HitBox->setUsed(false);
		}
		m_CurrentAni->setPosition(this->getHitBox()->getPosition());
		m_CurrentAni->update(deltaTime);
	}
}

void Bullet::bulletRender(sf::RenderWindow* window)
{
	if (m_HitBox->isUsed()) {
		window->draw(*m_CurrentAni);
		window->draw(*m_HitBox);
	}
}

HitBox* Bullet::getHitBox()
{
	return m_HitBox;
}


void Bullet::resetToStartStatus()
{
	m_HitBox->setPosition(m_StartPos);
	m_MoveAni->resetFrame();
	m_ImpactAni->resetFrame();
	m_CurrentTime = 0;
	m_CurrentAni = m_MoveAni;
}
