#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSAttack : public IPState {
public:
	PSAttack(IPlayer* player);

	void ipstateInit();
	void ipstateUpdate(float deltaTime);
	void ipstateRender(sf::RenderWindow* window);

	Animation* getAnimation() {
		return m_Animation;
	}

	void stateReset();
private:
	float m_CurrentTime;
	IPlayer* m_Player;
	Animation* m_Animation;
};