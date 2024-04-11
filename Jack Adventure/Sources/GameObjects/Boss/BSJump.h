#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSJump : public IBState {
public:
	BSJump(IBoss* boss);

	void ibstateInit();
	void ibstateUpdate(float deltaTime);
	void ibstateRender(sf::RenderWindow* window);

	Animation* getAnimation() {
		return m_Animation;
	}

	void stateReset();
private:
	float m_CurrentTime;
	float m_ChangeStateTime;
	IBoss* m_Boss;
	Animation* m_Animation;
};