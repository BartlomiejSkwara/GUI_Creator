#pragma once
#include <SFML/Graphics/Text.hpp>
#include "../GUI_Creator/Code/GUI/Parents/Object.h"
#include <SFML/Graphics/Sprite.hpp>
#include "../GUI_Creator/Code/Events and stuff/Input/MouseInput.h"
class ImageObject : public Object
{

private:

	//Buttons texture 
	sf::Sprite  m_sprite;
	std::string m_textureName;
public:

	ImageObject(const std::string& textureName, float positionX, float positionY, const std::function<void()>& func = [](){}, float scale = 1.f);
	virtual ~ImageObject();


	void fitBorderToSprite();


	//Change the position
	virtual void setPosition(const sf::Vector2i& position) override;
	virtual void setPosition(int x, int y) override;
	void setTexture(const std::string& textureName);

	//Change the offset from position
	virtual void move(const sf::Vector2i& offset) override;
	virtual void move(int x, int y) override;


	//Renders the text and the frame 
	virtual void render(sf::RenderTarget* target) override;
	
	

	// Func responsible for the stuff button does in update loop
	virtual Object* updateClickables(sf::Vector2f& mousePosition) override;


	//Gettery
	
	//Function returns the sfml text object u;sed to render the text
	const sf::Sprite* getSprite();
	//Function returns name of the file storing texture
	const std::string& getTextureName();

	


	// Inherited via Object
	virtual void setScale(float x, float y) override;

	virtual std::pair<float, float> getScale() override;


	// Inherited via MouseEventHandler
	virtual bool handleEvent(Event& event) override;
};
