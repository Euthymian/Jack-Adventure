#include "BulletManager.h"

BullerManager::BullerManager()
{
	m_CurrentTime = 0.f;
	m_BulletNum = 10;
}

BullerManager::~BullerManager()
{
	for (Bullet* each : m_ListBullet) {
		if (each != nullptr) delete each;
	}
	m_ListBullet.clear();
}

void BullerManager::bulletMngInit(CollisionManager& collisionManager)
{
	for (int i = 0; i < m_BulletNum; i++) {
		Bullet* bullet = new Bullet();
		bullet->bulletInit();
		bullet->getHitBox()->setAlive(false);
		bullet->getHitBox()->setUsed(false);
		//bullet->getHitBox()->setPosition(200, ground - 10);
		m_ListBullet.push_back(bullet);
		collisionManager.addObj(bullet->getHitBox());
	}
}

void BullerManager::bulletMngUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	for (auto each : m_ListBullet) {
		each->bulletUpdate(deltaTime);
	}
}

void BullerManager::bulletMngRender(sf::RenderWindow* window)
{
	for (auto each : m_ListBullet) {
		each->bulletRender(window);
	}
}

void BullerManager::Fire(sf::Vector2f startPos)
{
	Bullet* bullet = nullptr;
	for (auto each : m_ListBullet) {
		if (!each->getHitBox()->isAlive() && !each->getHitBox()->isUsed()) {
			bullet = each;
			break;
		}
	}
	if (bullet == nullptr) { 
		return; 
	}
	bullet->getHitBox()->setAlive(true);
	bullet->getHitBox()->setUsed(true);
	bullet->setStartPos(startPos);
	bullet->resetToStartStatus();
}