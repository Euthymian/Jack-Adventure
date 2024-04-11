#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
	m_Background = new Layer();
	m_Title = new sf::Text();
}

GSHighScore::~GSHighScore()
{
	delete m_Title;
	delete m_Background;
	for (auto bnt : m_BntList) {
		delete bnt;
	}
	for (auto score : m_ScoreList) {
		delete score;
	}
}

void GSHighScore::gsExit()
{
}

void GSHighScore::gsPause()
{
}

void GSHighScore::gsResume()
{
}

void GSHighScore::gsInit()
{
	printf("HighScore\n");

	// Set background
	m_Background->layerInit("Background/Background",50);

	// Title
	m_Title->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_Title->setString("Hall of fame");
	m_Title->setFillColor(sf::Color::Red);
	m_Title->setScale(1.3, 1.3);
	sf::FloatRect text_properties = m_Title->getLocalBounds();
	m_Title->setOrigin(text_properties.width / 2, text_properties.height / 2);
	m_Title->setPosition(screenWidth / 2, 85);

	//Buttons
	GameButton* button;

	button = new GameButton();
	button->bntInit("close_2");
	button->setPosition(screenWidth * 12 / 13, screenHeight * 0.5 / 5);
	button->setScale(0.5, 0.5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->popState();
		});
	m_BntList.push_back(button);

	for (int i = 0; i < ScoreManager::getInstance()->getNum(); i++) {
		sf::Text* text = new sf::Text();
		text->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
		text->setString(std::to_string(ScoreManager::getInstance()->getHighScoreList()[i]));
		text->setFillColor(sf::Color::Yellow);
		sf::FloatRect text_properties = text->getLocalBounds();
		text->setOrigin(text_properties.width / 2, text_properties.height / 2);
		text->setPosition(screenWidth / 2, 200 + 60*i);
		m_ScoreList.push_back(text);
	}
}

void GSHighScore::gsUpdate(float deltaTime)
{
	m_Background->layerUpdate(deltaTime);
	for (auto bnt : m_BntList) {
		bnt->bntUpdate(deltaTime);
	}
}

void GSHighScore::gsRender(sf::RenderWindow* window)
{
	m_Background->layerRender(window);
	window->draw(*m_Title);
	for (auto bnt : m_BntList) {
		bnt->bntRender(window);
	}
	for (auto score : m_ScoreList) {
		window->draw(*score);
	}
}
