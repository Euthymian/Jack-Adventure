#pragma once
#include <SFML/Graphics.hpp>
class Animation : public sf::Sprite {
public:
	Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
	void calculateRectSize();
	void calculateRectXY();
	void applyRect();
	virtual void update(float deltaTime);

	void setEndFrame(bool stop);
	virtual void resetFrame();

	sf::Vector2i getCurrentFrame() {
		return m_currentFrame;
	}
protected:
	sf::Vector2i m_currentFrame;
	sf::Vector2i m_frameNum;

	float m_frameTime;
	float m_currentTime;

	sf::Vector2i m_rectXY;
	sf::Vector2i m_rectSize;
	sf::IntRect m_rect;

	bool m_stopAtLastFrame;
};