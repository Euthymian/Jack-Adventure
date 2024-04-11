#pragma once
#include "../../GameManager/ResourceManager.h"

class Creep {
public:
	Creep();
	~Creep();

	virtual void creepInit();
	virtual void creepUpdate(float deltaTime);
	virtual void creepRender(sf::RenderWindow* window);

	HitBox* getHitBox();

	void setStartPos(sf::Vector2f startPos);

	void resetToStartStatus();
protected:
	sf::Vector2f m_StartPos;

	HitBox* m_HitBox;

	Animation* m_CurrentAni;
	Animation* m_MoveAni;
	Animation* m_DieAni;
	Animation* m_DamagedAni;
	Animation* m_AttackAni;

	float m_DisappearTime;
	float m_CurrentTime;
};