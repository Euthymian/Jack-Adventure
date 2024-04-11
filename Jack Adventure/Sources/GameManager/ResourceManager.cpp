#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_Path = "../Data/";
	m_TexturePath = m_Path + "Texture/";
	m_FontPath = m_Path + "Font/";
	m_SoundPath = m_Path + "Sound/";
}

ResourceManager::~ResourceManager()
{
	for (auto each : m_MapTexture) {
		if (each.second != nullptr) {
			delete each.second;
		}
	}
	m_MapTexture.clear();

	for (auto each : m_MapFont) {
		if (each.second != nullptr) {
			delete each.second;
		}
	}
	m_MapFont.clear();

	for (auto each : m_MapSound) {
		if (each.second != nullptr) {
			delete each.second;
		}
	}
	m_MapSound.clear();
}

void ResourceManager::addTexture(std::string name)
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(m_TexturePath + name + ".png");
	std::map<std::string, sf::Texture*>::iterator existedTexture = m_MapTexture.find(name);
	if (existedTexture != m_MapTexture.end()) {
		return;
	}
	m_MapTexture.insert({name, texture});
}

void ResourceManager::removeTexture(std::string name)
{
	std::map<std::string, sf::Texture*>::iterator existedTexture = m_MapTexture.find(name);
	if (existedTexture == m_MapTexture.end()) {
		return;
	}
	if (existedTexture->second != nullptr) delete existedTexture->second;
	m_MapTexture.erase(existedTexture);
}

sf::Texture* ResourceManager::getTexture(std::string name)
{
	auto existedTexture = m_MapTexture.find(name);
	if (existedTexture != m_MapTexture.end()) {
		return existedTexture->second;
	}

	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(m_TexturePath + name + ".png");
	m_MapTexture.insert({ name, texture });
	return texture;
}

void ResourceManager::addFont(std::string name)
{
	sf::Font* font = new sf::Font;
	font->loadFromFile(m_FontPath + name + ".ttf");
	std::map<std::string, sf::Font*>::iterator existedFont = m_MapFont.find(name);
	if (existedFont != m_MapFont.end()) {
		return;
	}
	m_MapFont.insert({ name, font });
}

void ResourceManager::removeFont(std::string name)
{
	std::map<std::string, sf::Font*>::iterator existedFont = m_MapFont.find(name);
	if (existedFont == m_MapFont.end()) {
		return;
	}
	if (existedFont->second != nullptr) delete existedFont->second;
	m_MapFont.erase(existedFont);
}

sf::Font* ResourceManager::getFont(std::string name)
{
	auto existedFont = m_MapFont.find(name);
	if (existedFont != m_MapFont.end()) {
		return existedFont->second;
	}

	sf::Font* font = new sf::Font;
	font->loadFromFile(m_FontPath + name + ".ttf");
	m_MapFont.insert({ name, font });
	return font;
}

void ResourceManager::addSound(std::string name)
{
	sf::Sound* sound = new sf::Sound();
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(m_SoundPath + name + ".wav");
	sound->setBuffer(*buffer);

	std::map<std::string, sf::Sound*>::iterator existedSound = m_MapSound.find(name);
	if (existedSound != m_MapSound.end()) {
		return;
	}
	m_MapSound.insert({ name, sound });
}

void ResourceManager::removeSound(std::string name)
{
	std::map<std::string, sf::Sound*>::iterator existedSound = m_MapSound.find(name);
	if (existedSound != m_MapSound.end()) {
		return;
	}
	if (existedSound->second != nullptr) delete existedSound->second;
	m_MapSound.erase(existedSound);
}

sf::Sound* ResourceManager::getSound(std::string name)
{
	auto existedSound = m_MapSound.find(name);
	if (existedSound != m_MapSound.end()) {
		return existedSound->second;
	}

	sf::Sound* sound = new sf::Sound();
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	buffer->loadFromFile(m_SoundPath + name + ".wav");
	sound->setBuffer(*buffer);
	m_MapSound.insert({ name, sound });
	return sound;
}
