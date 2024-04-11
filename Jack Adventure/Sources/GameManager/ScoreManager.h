#pragma once
#include "ResourceManager.h"
#include "../Singleton.h"

class ScoreManager : public CSingleton<ScoreManager>{
public:
	ScoreManager();

	void setCurrentScore(int score);
	int getCurrentScore();

	void updateHighScore(int score);

	int getBestScore();

	int getNum();
	int* getHighScoreList();

	void readFile();
	void writeFile();
private:
	int m_CurrentScore;
	int m_Num;
	int m_HighScore[5];
};