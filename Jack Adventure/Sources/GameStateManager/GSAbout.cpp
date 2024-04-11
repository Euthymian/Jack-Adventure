#include "GSAbout.h"

GSAbout::GSAbout()
{
	m_Background = new Layer();
}

GSAbout::~GSAbout()
{
}

void GSAbout::gsExit()
{
}

void GSAbout::gsPause()
{
}

void GSAbout::gsResume()
{
}

void GSAbout::gsInit()
{
	printf("About\n");

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

void GSAbout::gsUpdate(float deltaTime)
{
	m_Background->layerUpdate(deltaTime);
	for (auto bnt : m_BntList) {
		bnt->bntUpdate(deltaTime);
	}
}

void GSAbout::gsRender(sf::RenderWindow* window)
{
	m_Background->layerRender(window);
	for (auto bnt : m_BntList) {
		bnt->bntRender(window);
	}
}
