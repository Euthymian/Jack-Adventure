#pragma once
#include <SFML/Graphics.hpp>
#include <list>

enum TAG
{
	PLAYER,
	CREEP,
	BOSS,
	BOSS_BULLET,
	PLAYER_BULLET,
};

class HitBox : public sf::RectangleShape {
public:
	HitBox(sf::Vector2i size);
	~HitBox();

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
	void setHitBoxSize(sf::Vector2f size);

	TAG getTag() { 
		return m_Tag; 
	}
	void setTag(TAG tag) {
		m_Tag = tag;
	}

	bool isAlive() { 
		return m_IsAlive; 
	}
	void setAlive(bool status) {
		m_IsAlive = status;
	}

	bool isUsed() {
		return m_IsUsed;
	}
	void setUsed(bool status) {
		m_IsUsed = status;
	}
private:
	sf::Vector2f m_Velocity;
	bool m_IsAlive; // object with this hitbox is alive or not
	bool m_IsUsed; // object with this hitbox is being used or not
	TAG m_Tag;
};