#pragma once
#include "../../GameManager/ResourceManager.h"
#include "Bullet.h"

class BullerManager {
public:
	BullerManager();
	~BullerManager();

	void bulletMngInit(CollisionManager& collisionManager);
	void bulletMngUpdate(float deltaTime);
	void bulletMngRender(sf::RenderWindow* window);

	void Fire(sf::Vector2f startPos);
private:
	std::list<Bullet*> m_ListBullet;
	int m_BulletNum;
	float m_CurrentTime;
};