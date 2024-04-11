#include "GSMenu.h"

GSMenu::GSMenu()
{
	m_Background = new Layer();
	m_GameName = new sf::Text();
}

GSMenu::~GSMenu()
{
}

void GSMenu::gsExit()
{
}

void GSMenu::gsPause()
{
}

void GSMenu::gsResume()
{
}

void GSMenu::gsInit()
{
	printf("Menu\n");
	// Set background
	m_Background->layerInit("Background/Background",50);

	// Set game's name
	m_GameName->setFont(*ResourceManager::getInstance()->getFont("Gigabot-K7YaZ"));
	m_GameName->setString("Jack's Adventure");
	m_GameName->setFillColor(sf::Color::Red);
	m_GameName->setScale(1.3, 1.3);
	sf::FloatRect text_properties = m_GameName->getLocalBounds();
	m_GameName->setOrigin(text_properties.width / 2, text_properties.height / 2);
	m_GameName->setPosition(screenWidth/2, 85);

	// Buttons
	GameButton* button;

	// Play button
	button = new GameButton();
	button->bntInit("play");
	button->setSize(sf::Vector2f(150,150));
	button->setOrigin(button->getSize().x / 2, button->getSize().y / 2);
	button->setPosition(screenWidth / 2, screenHeight * 2 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->changeState(GSTATE::PLAY);
	});
	m_BntList.push_back(button);

	// Setting button
	button = new GameButton();
	button->bntInit("settings");
	button->setPosition(screenWidth * 4 / 14, screenHeight * 3.5 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->changeState(GSTATE::SETTINGS);
	});
	m_BntList.push_back(button);

	// High scrore button
	button = new GameButton();
	button->bntInit("prize");
	button->setPosition(screenWidth * 6 / 14, screenHeight * 3.5 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->changeState(GSTATE::HIGHSCORE);
	});
	m_BntList.push_back(button);

	// About button
	button = new GameButton();
	button->bntInit("about");
	button->setPosition(screenWidth * 8 / 14, screenHeight * 3.5 / 5);
	button->setOnClick([]() {
		GameStateMachine::getInstance()->changeState(GSTATE::ABOUT);
	});
	m_BntList.push_back(button);

	// Exit button
	button = new GameButton();
	button->bntInit("close");
	button->setPosition(screenWidth * 10 / 14, screenHeight * 3.5 / 5);
	button->setOnClick([]() {
		WindowConnector::getInstance()->getWindow()->close();
	});
	m_BntList.push_back(button);

	ScoreManager::getInstance()->readFile();
}

void GSMenu::gsUpdate(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		GameStateMachine::getInstance()->changeState(PLAY);
	}
	m_Background->layerUpdate(deltaTime);
	for (auto bnt : m_BntList) {
		bnt->bntUpdate(deltaTime);
	}
}

void GSMenu::gsRender(sf::RenderWindow* window)
{
	m_Background->layerRender(window);
	window->draw(*m_GameName);
	for (auto bnt : m_BntList) {
		bnt->bntRender(window);
	}
}
