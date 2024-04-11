#pragma once
#include "../../GameManager/ResourceManager.h"

class Bullet {
public:
	Bullet();
	~Bullet();

	virtual void bulletInit();
	virtual void bulletUpdate(float deltaTime);
	virtual void bulletRender(sf::RenderWindow* window);

	HitBox* getHitBox();

	void resetToStartStatus();

	void setStartPos(sf::Vector2f startPos) {
		m_StartPos = startPos;
	}
protected:
	sf::Vector2f m_StartPos;

	HitBox* m_HitBox;

	Animation* m_CurrentAni;
	Animation* m_MoveAni;
	Animation* m_ImpactAni;

	float m_DisappearTime;
	float m_CurrentTime;
};