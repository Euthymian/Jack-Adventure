#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
    m_CurrentScore = 0;
    m_Num = 5;
    for (int& each : m_HighScore) {
        each = 0;
    }
}

void ScoreManager::setCurrentScore(int score)
{
    m_CurrentScore = score;
}

int ScoreManager::getCurrentScore()
{
    return m_CurrentScore;
}

void ScoreManager::updateHighScore(int score)
{
    for (int i = m_Num - 1; i >= 0; i--) {
        if (score > m_HighScore[i]) {
            m_HighScore[i] = score;
            break;
        }
    }
    // std::sort(m_HighScore, m_HighScore + m_Num, std::greater<int>());
    // Using lambda
    std::sort(m_HighScore, m_HighScore + m_Num, [](int a, int b) {return a > b; });
}

int ScoreManager::getBestScore()
{
    return m_HighScore[0];
}

int ScoreManager::getNum()
{
    return m_Num;
}

int* ScoreManager::getHighScoreList()
{
    return m_HighScore;
}

void ScoreManager::readFile()
{
    std::fstream input;
    input.open("../Data/Binary/HighScore.data", std::ios::binary | std::ios::in);
    input.read((char*)m_HighScore, sizeof(m_HighScore));
    input.close();
}

void ScoreManager::writeFile()
{
    std::fstream output;
    output.open("../Data/Binary/HighScore.data", std::ios::binary | std::ios::out);
    output.write((char*)m_HighScore, sizeof(m_HighScore));
    output.close();
}
