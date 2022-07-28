#pragma once
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <filesystem>
#include <unordered_map>
class ResourceManager
{
private:
	std::string m_directory;
	std::unordered_map<std::string, sf::Texture*> textures;
	std::unordered_map<std::string, sf::Font*> fonts;
public :
	ResourceManager(const std::string& dir);

	//Loads a single file into correct hashtable 
	void loadFile(const std::filesystem::path& dir);

	//Loads all files inside of Resources directory
	void loadAllFiles();

	
	sf::Texture* getTexture(const std::string& filename);
	sf::Font*    getFont(const std::string& filename);
	
};

