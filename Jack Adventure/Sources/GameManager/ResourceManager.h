#pragma once
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "../GameConfig.h"
#include "../GameObjects/GameButton.h"
#include "../GameObjects/AnimationV2.h"
#include "../GameObjects/HitBox.h"
#include "../GameObjects/Collision/Collision.h"
#include "SFML/Audio.hpp"

class ResourceManager : public CSingleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);
private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Font*> m_MapFont;
	std::map<std::string, sf::Sound*> m_MapSound;

	std::string m_Path;
	std::string m_TexturePath;
	std::string m_FontPath;
	std::string m_SoundPath;
};