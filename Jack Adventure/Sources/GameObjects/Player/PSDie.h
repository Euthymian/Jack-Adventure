#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSDie : public IPState {
public:
	PSDie(IPlayer* player);

	void ipstateInit();
	void ipstateUpdate(float deltaTime);
	void ipstateRender(sf::RenderWindow* window);

	Animation* getAnimation() {
		return m_Animation;
	}

	void stateReset();
private:
	IPlayer* m_Player;
	Animation* m_Animation;
	float m_CurrentTime;
	float m_ToNextStateTime;
	float m_Acceleration;
};