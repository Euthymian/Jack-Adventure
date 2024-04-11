#pragma once
#include "IBState.h"
#include "IBoss.h"

class BSAttack : public IBState {
public:
	BSAttack(IBoss* boss);

	void ibstateInit();
	void ibstateUpdate(float deltaTime);
	void ibstateRender(sf::RenderWindow* window);

	Animation* getAnimation() {
		return m_Animation;
	}

	void stateReset();

	void setFireStatus(bool available) {
		m_Fire = available;
	}
	bool getFireStatus() {
		return m_Fire;
	}
private:
	bool m_Fire;
	float m_CurrentTime;
	float m_ChangeStateTime;
	IBoss* m_Boss;
	Animation* m_Animation;
};