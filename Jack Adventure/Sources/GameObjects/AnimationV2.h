#pragma once
#include "Animation.h"

class AnimationV2 : public Animation {
public:
	AnimationV2(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int totalFrame);
	void update(float deltaTime);
	void resetFrame();
	int getTotalFrame() {
		return m_TotalFrame;
	}
	int getCurrentNumOfFrames() {
		return m_CurrentNumOfFrames;
	}
private:
	int m_TotalFrame;
	int m_CurrentNumOfFrames;
};
