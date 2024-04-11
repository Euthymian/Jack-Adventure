#pragma once
#include "GameStateBase.h"

class GSSettings : public GameStateBase {
public:
	GSSettings();
	virtual ~GSSettings();

	void gsExit();
	void gsPause();
	void gsResume();

	void gsInit();
	void gsUpdate(float deltaTime);
	void gsRender(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_BntList;
	Layer* m_Background;
};