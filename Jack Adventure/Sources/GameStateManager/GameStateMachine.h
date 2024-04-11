#pragma once
#include <list>
#include "../Singleton.h"
#include "../GameManager/ScoreManager.h"

class GameStateBase;

enum GSTATE {
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTINGS,
	ABOUT,
	HIGHSCORE,
	END,
};

class GameStateMachine : public CSingleton<GameStateMachine> {
public:
	GameStateMachine();
	~GameStateMachine();

	void changeState(GameStateBase* state);
	void changeState(GSTATE st);
	void pushState(GSTATE st);
	void popState();

	void performState();

	GameStateBase* currentState() const;
	GameStateBase* nextState() const;
	bool needToChangeState();
	bool hasState();

private:
	std::list<GameStateBase*> m_StateStack;
	GameStateBase* m_ActiveState;
	GameStateBase* m_NextState;
};