#pragma once
#include "../../GameManager/ResourceManager.h"

class Layer {
public:
	void layerInit(std::string name, float speed);
	void layerUpdate(float deltaTime);
	void layerRender(sf::RenderWindow* window);
private:
	sf::Sprite m_Image1;
	sf::Sprite m_Image2;
	sf::Texture* m_TextureLayer;
	float m_Speed;
};