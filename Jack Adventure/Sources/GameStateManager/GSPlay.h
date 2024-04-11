#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Player/Player.h"
#include "../GameObjects/Creep/Creep.h"
#include "../GameObjects/Creep/CreepManager.h"
#include "../GameObjects/Collision/Collision.h"
#include "../GameObjects/Boss/Boss.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void gsExit();
	void gsPause();
	void gsResume();

	void gsInit();
	void gsUpdate(float deltaTime);
	void gsRender(sf::RenderWindow* window);
private:
	float m_CurrentTime;

	ParallelBackground* m_Background;
	Player* m_Player;
	CreepManager m_CreepManager;
	Boss* m_Boss;
	CollisionManager m_CollisionMagager;
	int m_CurrentScore;
	sf::Text* m_Score;
};