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
	std::unordered_map<std::string, sf::Texture*> m_textures;
	std::unordered_map<std::string, sf::Font*> m_fonts;


	static ResourceManager* resourceManager;
	ResourceManager(const std::string& dir);
public :
	static ResourceManager* getResourceManager();

	//Loads a single file into correct hashtable 
	void loadFile(const std::filesystem::path& dir);

	//Loads all files inside of Resources directory
	void loadAllFiles();

	
	sf::Texture* getTexture(const std::string& filename);
	sf::Font*    getFont(const std::string& filename);



	
	//Functions returning boundries of unordered maps
	std::pair<std::unordered_map<std::string, sf::Font*>::const_iterator, std::unordered_map<std::string, sf::Font*>::const_iterator>
		getFontsIterators() const;

	std::pair<std::unordered_map<std::string, sf::Texture*>::const_iterator, std::unordered_map<std::string, sf::Texture*>::const_iterator>
		getTexturesIterators() const;
};

