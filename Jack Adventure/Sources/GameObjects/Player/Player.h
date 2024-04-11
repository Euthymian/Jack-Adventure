#pragma once
#include "IPlayer.h"

class Player : public IPlayer{
public:
	Player();
	~Player();

	void changeNextState(IPState::PSTATE nextState);

	void playerInit();
	void playerUpdate(float deltaTime);
	void playerRender(sf::RenderWindow* window);

	HitBox* getHitBox();
private:
	void performStateChange();

	IPState::PSTATE m_NextState;

	IPState* m_CurrentState;

	IPState* m_RunState;
	IPState* m_JumpState;
	IPState* m_FallState;
	IPState* m_DieState;
	IPState* m_AttackState;

	HitBox* m_HitBox;
};