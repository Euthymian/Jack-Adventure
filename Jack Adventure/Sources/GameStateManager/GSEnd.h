#pragma once
#include "GameStateBase.h"

class GSEnd : public GameStateBase {
public:
	GSEnd();
	virtual ~GSEnd();

	void gsExit();
	void gsPause();
	void gsResume();

	void gsInit();
	void gsUpdate(float deltaTime);
	void gsRender(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_BntList;
	Layer* m_Background;
	sf::Text* m_CurrentScore;
	sf::Text* m_BestScore;
};