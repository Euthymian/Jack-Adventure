#include "Collision.h"

void CollisionManager::addObj(HitBox* hitBox)
{
    m_ListObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::collisionUpdate()
{
    for (HitBox* r1 : m_ListObj) {
        if (!r1->isAlive()) continue;
        for (HitBox* r2 : m_ListObj) {
            if (!r2->isAlive()) continue;

            if (r1->getTag() == r2->getTag()) continue;
            if (!checkCollision(r1, r2)) continue;

            if (r1->getTag() == PLAYER && r2->getTag() == CREEP) {
                r1->setAlive(false);
                r2->setAlive(false);
            }

            if ((r1->getTag() == PLAYER || r1->getTag() == CREEP) && r2->getTag() == BOSS_BULLET) {
                r1->setAlive(false);
                r2->setAlive(false);
            }

            if (r1->getTag() == PLAYER && r2->getTag() == BOSS) {
                r1->setAlive(false);
            }
        }
    }
}
