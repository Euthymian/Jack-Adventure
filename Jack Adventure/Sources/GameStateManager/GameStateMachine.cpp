#include "GameStateMachine.h"
#include "GameStateBase.h"

GameStateMachine::GameStateMachine()
{
    m_ActiveState = nullptr;
    m_NextState = nullptr;
}

GameStateMachine::~GameStateMachine()
{
    while (!m_StateStack.empty()) {
        delete m_StateStack.back();
        m_StateStack.pop_back();
    }
}

void GameStateMachine::changeState(GameStateBase* state)
{
    m_NextState = state;
}

void GameStateMachine::changeState(GSTATE st)
{
    GameStateBase* gs = GameStateBase::createState(st);
    changeState(gs);
}

void GameStateMachine::pushState(GSTATE st)
{
    GameStateBase* gs = GameStateBase::createState(st);
    if (!m_StateStack.empty()) {
        m_StateStack.back()->gsPause();
    }
    m_NextState = gs;
}

void GameStateMachine::popState()
{
    if (!m_StateStack.empty()) {
        m_StateStack.back()->gsExit();
        m_StateStack.pop_back();
    }
    if (!m_StateStack.empty()) {
        m_StateStack.back()->gsResume();
    }
    m_ActiveState = m_StateStack.back();
}

void GameStateMachine::performState()
{
    if (m_NextState != nullptr) {
        if (!m_StateStack.empty()) {
            m_StateStack.back()->gsExit();
        }
        m_StateStack.push_back(m_NextState);
        m_StateStack.back()->gsInit();
        m_ActiveState = m_NextState;
    }
    m_NextState = nullptr;
}

GameStateBase* GameStateMachine::currentState() const
{
    return m_ActiveState;
}

GameStateBase* GameStateMachine::nextState() const
{
    return m_NextState;
}

bool GameStateMachine::needToChangeState()
{
    return m_NextState != nullptr;
}

bool GameStateMachine::hasState()
{
    return m_StateStack.size() > 0;
}
