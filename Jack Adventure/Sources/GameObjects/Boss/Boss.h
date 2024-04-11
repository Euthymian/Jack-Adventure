#pragma once
#include "IBoss.h"
#include "../Collision/Collision.h"

class Boss : public IBoss {
public:
	Boss();
	~Boss();

	void changeNextState(IBState::BSTATE nextState);

	void bossInit(CollisionManager& collisionManager);
	void bossUpdate(float deltaTime);
	void bossRender(sf::RenderWindow* window);

	HitBox* getHitBox();
	BullerManager* getBulletManager();
private:
	void performStateChange();

	IBState::BSTATE m_NextState;

	IBState* m_CurrentState;

	IBState* m_JumpState;
	IBState* m_Jump_BiteState;
	IBState* m_AttackState;

	BullerManager* m_BulletManager;

	HitBox* m_HitBox;
};