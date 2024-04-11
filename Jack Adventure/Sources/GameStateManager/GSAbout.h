#pragma once
#include "GameStateBase.h"

class GSAbout : public GameStateBase {
public:
	GSAbout();
	virtual ~GSAbout();

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