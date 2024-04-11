#include "Application.h"
#include "GameStateManager/GameStateBase.h"

void Application::appInit()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), gameTitle, sf::Style::Default);
	m_window->setVerticalSyncEnabled(false);
	m_window->setFramerateLimit(100);
	GameStateMachine::getInstance()->changeState(GSTATE::INTRO);
	WindowConnector::getInstance()->setWindow(m_window);
	srand(time(NULL));
}

void Application::appUpdate(float deltaTime)
{
	if (GameStateMachine::getInstance()->needToChangeState()) {
		GameStateMachine::getInstance()->performState();
	}
	GameStateMachine::getInstance()->currentState()->gsUpdate(deltaTime);
}

void Application::appRender()
{
	m_window->clear(sf::Color::Black);
	// Draw something
	GameStateMachine::getInstance()->currentState()->gsRender(m_window);
	m_window->display();
}

void Application::appRun()
{
	appInit();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (m_window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window->close();
			}
		}
		appUpdate(deltaTime);
		appRender();
	}
}

Application::~Application()
{
	if (m_window != NULL) delete m_window;
}