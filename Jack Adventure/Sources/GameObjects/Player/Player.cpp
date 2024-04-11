#include "Player.h"
#include "PSRun.h"
#include "PSJump.h"
#include "PSFall.h"
#include "PSDie.h"
#include "PSAttack.h"

Player::Player()
{
	m_NextState = IPState::SNULL; // this line makes m_NextState doesnt have default value of first element in enum
	m_RunState = new PSRun(this);
	m_JumpState = new PSJump(this);
	m_FallState = new PSFall(this);
	m_DieState = new PSDie(this);
	m_AttackState = new PSAttack(this);
	m_CurrentState = m_RunState;
}

Player::~Player()
{
	if (m_RunState != nullptr) {
		delete m_RunState;
		m_RunState = nullptr;
	}
	if (m_JumpState != nullptr) {
		delete m_JumpState;
		m_JumpState = nullptr;
	}
	if (m_FallState != nullptr) {
		delete m_FallState;
		m_FallState = nullptr;
	}
	if (m_DieState != nullptr) {
		delete m_DieState;
		m_DieState = nullptr;
	}
	if (m_AttackState != nullptr) {
		delete m_AttackState;
		m_AttackState = nullptr;
	}
	m_CurrentState = nullptr;
}

void Player::changeNextState(IPState::PSTATE nextState)
{
	m_NextState = nextState;
}

void Player::playerInit()
{
	m_RunState->ipstateInit();
	m_JumpState->ipstateInit();
	m_FallState->ipstateInit();
	m_DieState->ipstateInit();
	m_AttackState->ipstateInit();

	m_HitBox = new HitBox(sf::Vector2i(23, 32));
	m_HitBox->setPosition(screenWidth * 4 / 9, ground);
	m_HitBox->setVelocity(sf::Vector2f(300, 640));
	m_HitBox->setTag(PLAYER);
}

void Player::playerUpdate(float deltaTime)
{
	performStateChange();
	m_CurrentState->ipstateUpdate(deltaTime);
}

void Player::playerRender(sf::RenderWindow* window)
{
	m_CurrentState->ipstateRender(window);
	window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange()
{
	if (m_NextState != IPState::PSTATE::SNULL) {
		switch (m_NextState)
		{
		case IPState::PSTATE::RUN: // case IPState::RUN:
			m_CurrentState = m_RunState;
			break;
		case IPState::PSTATE::JUMP:
			m_CurrentState = m_JumpState;
			break;
		case IPState::PSTATE::FALL:
			m_CurrentState = m_FallState;
			break;
		case IPState::PSTATE::DIE:
			m_CurrentState = m_DieState;
			break;
		case IPState::PSTATE::ATTACK:
			m_CurrentState = m_AttackState;
			break;
		default:
			break;
		}

		m_NextState = IPState::PSTATE::SNULL;
		m_CurrentState->stateReset();
	}
}
