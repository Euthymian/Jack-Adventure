#include "Animation.h"

Animation::Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime)
{
	m_frameNum = frameNum;
	m_frameTime = frameTime;
	this->setTexture(texture);
	m_currentFrame = sf::Vector2i(0, 0);
	m_currentTime = 0.1f;
	calculateRectXY();
	calculateRectSize();
	applyRect();
	this->setOrigin(sf::Vector2f(m_rectSize / 2));

	m_stopAtLastFrame = false;
}

void Animation::calculateRectSize()
{
	m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void Animation::calculateRectXY()
{
	m_rectXY = sf::Vector2i(m_currentFrame.x * m_rectSize.x, m_currentFrame.y * m_rectSize.y);
}

void Animation::applyRect()
{
	m_rect = sf::IntRect(m_rectXY, m_rectSize);
	this->setTextureRect(m_rect);
}

void Animation::update(float deltaTime)
{
	if (m_currentFrame.x == m_frameNum.x - 1 && m_stopAtLastFrame) {
		return;
	}
	m_currentTime += deltaTime;
	if (m_currentTime >= m_frameTime) {
		m_currentFrame.x++;
		if (m_currentFrame.x == m_frameNum.x) {
			m_currentFrame.x = 0;
		}
		calculateRectXY();
		applyRect();
		m_currentTime -= m_frameTime;
	}
}

void Animation::setEndFrame(bool stop)
{
	m_stopAtLastFrame = stop;
}

void Animation::resetFrame()
{
	m_currentFrame = sf::Vector2i(0, 0);
	m_currentTime = 0;
	calculateRectXY();
	applyRect();
}
