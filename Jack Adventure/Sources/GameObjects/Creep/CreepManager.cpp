#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_CurrentTime = 0.f;
	m_SpawnTime = 1.4f;
	m_CreepNum = 10;
}

CreepManager::~CreepManager()
{
	for (Crow* each : m_ListCrow) {
		if (each != nullptr) delete each;
	}
	m_ListCrow.clear();

	for (Bat* each : m_ListBat) {
		if (each != nullptr) delete each;
	}
	m_ListBat.clear();
}

void CreepManager::creepMngInit(CollisionManager& collisionManager)
{
	for (int i = 0; i < m_CreepNum; i++) {
		Crow* crow = new Crow();
		crow->creepInit();
		crow->getHitBox()->setAlive(false);
		crow->getHitBox()->setUsed(false);
		m_ListCrow.push_back(crow);
		collisionManager.addObj(crow->getHitBox());

		Bat* bat = new Bat();
		bat->creepInit();
		bat->getHitBox()->setAlive(false);
		bat->getHitBox()->setUsed(false);
		m_ListBat.push_back(bat);
		collisionManager.addObj(bat->getHitBox());
	}
}

void CreepManager::creepMngUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;

	if (m_CurrentTime >= m_SpawnTime) {
		CrowSpawn();
		BatSpawn();
		m_CurrentTime = 0;
	}

	for (auto each : m_ListBat) {
		each->creepUpdate(deltaTime);
	}
	for (auto each : m_ListCrow) {
		each->creepUpdate(deltaTime);
	}
}

void CreepManager::creepMngRender(sf::RenderWindow* window)
{
	for (auto each : m_ListBat) {
		each->creepRender(window);
	}
	for (auto each : m_ListCrow) {
		each->creepRender(window);
	}
}

void CreepManager::CrowSpawn()
{
	Creep* creep = nullptr;
	for (auto each : m_ListCrow) {
		if (!each->getHitBox()->isAlive() && !each->getHitBox()->isUsed()) {
			creep = each;
			break;
		}
	}
	if (creep == nullptr) { return; }
	creep->getHitBox()->setAlive(true);
	creep->getHitBox()->setUsed(true);
	creep->getHitBox()->setVelocity(sf::Vector2f(150 + rand() % (50 + 1), 0));
	creep->setStartPos(sf::Vector2f(sf::Vector2f(screenWidth + rand()%(100-50+1)+50, ground)));
	creep->resetToStartStatus();
}

void CreepManager::BatSpawn()
{
	Creep* creep = nullptr;
	for (auto each : m_ListBat) {
		if (!each->getHitBox()->isAlive() && !each->getHitBox()->isUsed()) {
			creep = each;
			break;
		}
	}
	if (creep == nullptr) { return; }
	creep->getHitBox()->setAlive(true);
	creep->getHitBox()->setUsed(true);
	creep->getHitBox()->setVelocity(sf::Vector2f(225 + rand() % (50 + 1), 0));
	creep->setStartPos(sf::Vector2f(sf::Vector2f(screenWidth + rand()%(100-50+1) + 50, screenHeight * 3 / 5 - rand()%(screenHeight/5 + 1))));
	creep->resetToStartStatus();
}
