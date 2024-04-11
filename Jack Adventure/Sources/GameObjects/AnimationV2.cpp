#include "AnimationV2.h"

AnimationV2::AnimationV2(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int totalFrame)
	:Animation(texture,frameNum,frameTime)
{
	m_TotalFrame = totalFrame;
	m_CurrentNumOfFrames = 1;
}

void AnimationV2::update(float deltaTime)
{
	if (m_stopAtLastFrame && m_CurrentNumOfFrames == m_TotalFrame) {
		return;
	}
	m_currentTime += deltaTime;
	if (m_currentTime >= m_frameTime) {
		m_currentFrame.x++;
		m_CurrentNumOfFrames++;
		if (m_currentFrame.x == m_frameNum.x && m_CurrentNumOfFrames <= m_TotalFrame) {
			m_currentFrame.y++;
			m_currentFrame.x = 0;
		}
		else if (m_CurrentNumOfFrames > m_TotalFrame) {
			m_CurrentNumOfFrames = 1;
			m_currentFrame = sf::Vector2i(0, 0);
		}
		//printf("%d\n", m_CurrentNumOfFrames);
		calculateRectXY();
		applyRect();
		m_currentTime -= m_frameTime;
	}
}

void AnimationV2::resetFrame()
{
	m_CurrentNumOfFrames = 1;
	Animation::resetFrame();
}
