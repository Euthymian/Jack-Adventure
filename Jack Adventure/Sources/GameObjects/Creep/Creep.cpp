#include "Creep.h"

Creep::Creep()
{
	m_DisappearTime = 3;
	m_CurrentTime = 0;
}

Creep::~Creep()
{
	m_CurrentAni = nullptr;
	if (m_MoveAni != nullptr) {
		delete m_MoveAni;
		m_MoveAni = nullptr;
	}
	if (m_DieAni != nullptr) {
		delete m_DieAni;
		m_DieAni = nullptr;
	}
	if (m_DamagedAni != nullptr) {
		delete m_DamagedAni;
		m_DamagedAni = nullptr;
	}
	if (m_AttackAni != nullptr) {
		delete m_AttackAni;
		m_AttackAni = nullptr;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
		m_HitBox = nullptr;
	}
}

void Creep::creepInit()
{
	
}

void Creep::creepUpdate(float deltaTime)
{
	if (m_HitBox->isUsed()) {
		if (m_HitBox->isAlive()) m_HitBox->move(-m_HitBox->getVelocity().x * deltaTime, 0);
		else {
			m_CurrentTime += deltaTime;
			m_CurrentAni = m_DieAni;
			m_CurrentAni->setEndFrame(true);
			if (m_CurrentTime >= m_DisappearTime) {
				m_HitBox->setUsed(false);
			}
		}
		if (m_HitBox->getPosition().x <= -50) {
			m_HitBox->setAlive(false);
			m_HitBox->setUsed(false);
		}
		m_CurrentAni->setPosition(this->getHitBox()->getPosition());
		m_CurrentAni->update(deltaTime);
	}
}

void Creep::creepRender(sf::RenderWindow* window)
{
	if (m_HitBox->isUsed()) {
		window->draw(*m_CurrentAni);
		window->draw(*m_HitBox);
	}
}

HitBox* Creep::getHitBox()
{
	return m_HitBox;
}

void Creep::setStartPos(sf::Vector2f startPos)
{
	m_StartPos = startPos;
}

void Creep::resetToStartStatus()
{
	m_HitBox->setPosition(m_StartPos);
	m_MoveAni->resetFrame();
	m_DieAni->resetFrame();
	m_CurrentTime = 0;
	m_CurrentAni = m_MoveAni;
}
