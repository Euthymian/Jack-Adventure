#pragma once
#include "../HitBox.h"

class CollisionManager {
public:
	void addObj(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	void collisionUpdate();
private:
	std::list<HitBox*> m_ListObj;
};