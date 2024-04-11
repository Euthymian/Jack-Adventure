#pragma once
#include "IBState.h"
#include "../Bullet/BulletManager.h"
#include "../HitBox.h"

class IBoss {
public:
	virtual void changeNextState(IBState::BSTATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
	virtual BullerManager* getBulletManager() = 0;
};