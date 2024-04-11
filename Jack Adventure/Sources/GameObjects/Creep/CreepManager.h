#pragma once
#include "../../GameManager/ResourceManager.h"
#include "Bat.h"
#include "Crow.h"

class CreepManager {
public:
	CreepManager();
	~CreepManager();

	void creepMngInit(CollisionManager& collisionManager);
	void creepMngUpdate(float deltaTime);
	void creepMngRender(sf::RenderWindow* window);
private:
	void CrowSpawn();
	void BatSpawn();
	std::list<Crow*> m_ListCrow;
	std::list<Bat*> m_ListBat;
	int m_CreepNum;
	float m_SpawnTime;
	float m_CurrentTime;
};