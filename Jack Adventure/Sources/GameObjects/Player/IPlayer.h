#pragma once
#include "IPState.h"
#include "../HitBox.h"

class IPlayer {
public:
	virtual void changeNextState(IPState::PSTATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};