#include "ResourceManager.h"

ResourceManager* ResourceManager::resourceManager = nullptr;

ResourceManager::ResourceManager(const std::string& dir):m_directory(dir)
{
    loadAllFiles();
}

ResourceManager* ResourceManager::getResourceManager()
{
    if (!resourceManager)
    {
        resourceManager = new ResourceManager("../Resources/");
    }
    
    return resourceManager;
}

void ResourceManager::loadFile(const std::filesystem::path& dir)
{
    static std::string temp = "";
    temp = dir.extension().string();
    if (temp == ".jpg"||temp == ".png")
    {
        sf::Texture* tempTexture = new sf::Texture();
        if (tempTexture->loadFromFile(dir.string())) 
        {
            m_textures.insert_or_assign(dir.filename().string(), tempTexture);
        }
        else
        {
            std::cout << "ERROR::RESOURCEMANAGER::Failed to load texture " << dir.string() << std::endl;        
        }
    }
    else if (temp == ".ttf")
    {
        sf::Font* tempFont = new sf::Font();
        if (tempFont->loadFromFile(dir.string()))
        {
            m_fonts[dir.filename().string()]=tempFont;
            //std::cout << dir.string() <<" "<< fonts.size()<< std::endl;
            
        }
        else
        {
            std::cout << "ERROR::RESOURCEMANAGER::Failed to load font " << dir.string() << std::endl;
        }
              
    }


}

void ResourceManager::loadAllFiles()
{
    try
    {
        for (const auto& entry : std::filesystem::directory_iterator(m_directory))
        {
            loadFile(entry.path());
        }
    }
    catch (std::filesystem::filesystem_error)
    {
        std::cout << "ERROR::RESOURCEMANAGER::Brak folderu z zasobami !!!";
    }

}

sf::Texture* ResourceManager::getTexture(const std::string& filename)
{
    try
    {
        return m_textures.at(filename);
    }
    catch (const std::exception&)
    {
        std::cout << "ERROR::RESOURCEMANAGER::tried to use nonexistant texture::" << filename << std::endl;
    }
    
}

sf::Font* ResourceManager::getFont(const std::string& filename)
{
    try
    {
        return m_fonts.at(filename);
    }
    catch (std::out_of_range)
    {
        std::cout << "ERROR::RESOURCEMANAGER::tried to use nonexistant font::" << filename << std::endl;
    }
    
    
    
    
}




std::pair<std::unordered_map<std::string, sf::Font*>::const_iterator, std::unordered_map<std::string, sf::Font*>::const_iterator>
ResourceManager::getFontsIterators() const
{
    
    return { m_fonts.begin(), m_fonts.end()};
}

std::pair<std::unordered_map<std::string, sf::Texture*>::const_iterator, std::unordered_map<std::string, sf::Texture*>::const_iterator> ResourceManager::getTexturesIterators() const
{
    return { m_textures.begin(), m_textures.end() };
}


