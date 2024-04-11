#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_IntroSprite = new sf::Sprite();
	m_MyName = new sf::Text();
	//m_BackgroundMusic = new sf::Music();
	m_CurrentTime = 0;
}

GSIntro::~GSIntro()
{
}

void GSIntro::gsExit()
{
}

void GSIntro::gsPause()
{
}

void GSIntro::gsResume()
{
}

void GSIntro::gsInit()
{
	printf("Intro\n");
	m_MyName->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_MyName->setString("Made by \nTuanThanh");
	m_MyName->setFillColor(sf::Color::Black);
	m_MyName->setPosition(30, 30);

	sf::Texture* tex = ResourceManager::getInstance()->getTexture("Intro");
	m_IntroSprite->setTexture(*tex);
	m_IntroSprite->setPosition(0, int(screenHeight - tex->getSize().y));

	//m_BackgroundMusic->openFromFile("../Data/Sound/background_intro.wav");
}

void GSIntro::gsUpdate(float deltaTime)
{
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= 3) {
		//m_BackgroundMusic->play();
		GameStateMachine::getInstance()->changeState(GSTATE::MENU);
	}
}

void GSIntro::gsRender(sf::RenderWindow* window)
{
	window->draw(*m_IntroSprite);
	window->draw(*m_MyName);
}
