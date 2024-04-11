#include "GSSettings.h"

GSSettings::GSSettings()
{
	m_Background = new Layer();
}

GSSettings::~GSSettings()
{
}

void GSSettings::gsExit()
{
}

void GSSettings::gsPause()
{
}

void GSSettings::gsResume()
{
}

void GSSettings::gsInit()
{
	printf("Settings\n");

	// Set background
	m_Background->layerInit("Background/Background",50);

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
}

void GSSettings::gsUpdate(float deltaTime)
{
	m_Background->layerUpdate(deltaTime);
	for (auto bnt : m_BntList) {
		bnt->bntUpdate(deltaTime);
	}
}

void GSSettings::gsRender(sf::RenderWindow* window)
{
	m_Background->layerRender(window);
	for (auto bnt : m_BntList) {
		bnt->bntRender(window);
	}
}
