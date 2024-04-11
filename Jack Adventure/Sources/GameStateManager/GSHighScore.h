#pragma once
#include "GameStateBase.h"

class GSHighScore : public GameStateBase {
public:
	GSHighScore();
	virtual ~GSHighScore();

	void gsExit();
	void gsPause();
	void gsResume();

	void gsInit();
	void gsUpdate(float deltaTime);
	void gsRender(sf::RenderWindow* window);
private:
	sf::Text* m_Title;
	std::list<GameButton*> m_BntList;
	std::list<sf::Text*> m_ScoreList;
	Layer* m_Background;
};