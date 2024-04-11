#include "Boss.h"
#include "BSAttack.h"
#include "BSJump.h"
#include "BSJump_Bite.h"

Boss::Boss()
{
	m_NextState = IBState::SNULL;
    m_JumpState = new BSJump(this);
    m_Jump_BiteState = new BSJump_Bite(this);
    m_AttackState = new BSAttack(this);
    m_CurrentState = m_JumpState;
	m_BulletManager = new BullerManager();
}

Boss::~Boss()
{
	if (m_JumpState != nullptr) {
		delete m_JumpState;
		m_JumpState = nullptr;
	}
	if (m_Jump_BiteState != nullptr) {
		delete m_Jump_BiteState;
		m_Jump_BiteState = nullptr;
	}
	if (m_AttackState != nullptr) {
		delete m_AttackState;
		m_AttackState = nullptr;
	}
	if (m_BulletManager != nullptr) {
		delete m_BulletManager;
		m_BulletManager = nullptr;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
		m_HitBox = nullptr;
	}
	m_CurrentState = nullptr;
}

void Boss::changeNextState(IBState::BSTATE nextState)
{
	m_NextState = nextState;
}

void Boss::bossInit(CollisionManager& collisionManager)
{
	m_HitBox = new HitBox(sf::Vector2i(240, 190));
	m_HitBox->setPosition(100, ground - 88);
	m_HitBox->setVelocity(sf::Vector2f(300, 800));
	m_HitBox->setTag(BOSS);

	m_JumpState->ibstateInit();
	m_Jump_BiteState->ibstateInit();
	m_AttackState->ibstateInit();
	m_BulletManager->bulletMngInit(collisionManager);
}

void Boss::bossUpdate(float deltaTime)
{
	performStateChange();
	m_BulletManager->bulletMngUpdate(deltaTime);
	m_CurrentState->ibstateUpdate(deltaTime);
}

void Boss::bossRender(sf::RenderWindow* window)
{
	m_BulletManager->bulletMngRender(window);
	m_CurrentState->ibstateRender(window);
	window->draw(*m_HitBox);
}

HitBox* Boss::getHitBox()
{
    return m_HitBox;
}

BullerManager* Boss::getBulletManager()
{
	return m_BulletManager;
}

void Boss::performStateChange()
{
	if (m_NextState != IBState::BSTATE::SNULL) {
		switch (m_NextState)
		{
		case IBState::BSTATE::JUMP:
			m_CurrentState = m_JumpState;
			break;
		case IBState::BSTATE::JUMP_BITE:
			m_CurrentState = m_Jump_BiteState;
			break;
		case IBState::BSTATE::ATTACK:
			m_CurrentState = m_AttackState;
			break;
		default:
			break;
		}

		m_NextState = IBState::BSTATE::SNULL;
		m_CurrentState->stateReset();
	}
}
