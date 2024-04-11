#include "GSEnd.h"

GSEnd::GSEnd()
{
	m_Background = new Layer();
	m_BestScore = new sf::Text();
	m_CurrentScore = new sf::Text();
}

GSEnd::~GSEnd()
{
	delete m_Background;
	delete m_BestScore;
	delete m_CurrentScore;
}

void GSEnd::gsExit()
{
}

void GSEnd::gsPause()
{
}

void GSEnd::gsResume()
{
}

void GSEnd::gsInit()
{
	printf("End\n");
	// Set background
	m_Background->layerInit("Background/Background", 50);

	// Buttons
	GameButton* button;

	// Play again button
	button = new GameButton();
	button->bntInit("restart");
	button->setPosition(screenWidth * 5 / 14, screenHeight * 4 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->popState();
		GameStateMachine::getInstance()->popState();
		GameStateMachine::getInstance()->changeState(PLAY);
	});
	m_BntList.push_back(button);

	// To MENU button
	button = new GameButton();
	button->bntInit("menu");
	button->setPosition(screenWidth * 9 / 14, screenHeight * 4 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->popState();
		GameStateMachine::getInstance()->popState();
	});
	m_BntList.push_back(button);

	// Update highscore
	int* currentScore = new int();
	*currentScore = ScoreManager::getInstance()->getCurrentScore();
	ScoreManager::getInstance()->updateHighScore(*currentScore);
	ScoreManager::getInstance()->writeFile();

	// Display current score
	m_CurrentScore->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_CurrentScore->setString("Current score: " + std::to_string(*currentScore));
	m_CurrentScore->setFillColor(sf::Color::Yellow);
	sf::FloatRect text_properties = m_CurrentScore->getLocalBounds();
	m_CurrentScore->setOrigin(text_properties.width / 2, text_properties.height / 2);
	m_CurrentScore->setPosition(screenWidth / 2, screenHeight / 2 - 100);

	// Display best score
	m_BestScore->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_BestScore->setString("Best score: " + std::to_string(ScoreManager::getInstance()->getBestScore()));
	m_BestScore->setFillColor(sf::Color::Yellow);
	text_properties = m_BestScore->getLocalBounds();
	m_BestScore->setOrigin(text_properties.width / 2, text_properties.height / 2);
	m_BestScore->setPosition(screenWidth / 2, 100);

	delete currentScore;
}

void GSEnd::gsUpdate(float deltaTime)
{
	m_Background->layerUpdate(deltaTime);
	for (auto bnt : m_BntList) {
		bnt->bntUpdate(deltaTime);
	}
}

void GSEnd::gsRender(sf::RenderWindow* window)
{
	m_Background->layerRender(window);
	window->draw(*m_CurrentScore);
	window->draw(*m_BestScore);
	for (auto bnt : m_BntList) {
		bnt->bntRender(window);
	}
}
