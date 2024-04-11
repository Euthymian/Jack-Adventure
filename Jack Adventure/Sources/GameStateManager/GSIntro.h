#pragma once
#include "GameStateBase.h"

class GSIntro : public GameStateBase {
public:
	GSIntro();
	virtual ~GSIntro();

	void gsExit();
	void gsPause();
	void gsResume();

	void gsInit();
	void gsUpdate(float deltaTime);
	void gsRender(sf::RenderWindow* window);
private:
	sf::Sprite* m_IntroSprite;
	sf::Text* m_MyName;
	float m_CurrentTime;
	//sf::Music* m_BackgroundMusic;
};