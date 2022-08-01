#pragma once
#include <SFML/Graphics/Text.hpp>
#include "../GUI_Creator/Code/GUI/Parents/Object.h"
class TextObject : public Object
{

private:

	//Buttons Label 
	sf::Text m_text;
	std::string m_fontName;

	short int m_characterSize;
public:

	TextObject(const std::string& fontName , std::string label, float positionX, float positionY, const std::function<void()>& func = [](){}, float sizeX = 100, float sizeY = 30, int charSize = 20, float scale = 1.f);
	virtual ~TextObject();

	//Text initialization
	void initText(const std::string& fontName, const std::string label);
	//This one just changes the string (use it if u already initialized the font )
	void initText(const std::string label);



	void fitBorderToText();


	//Change the position
	virtual void setPosition(const sf::Vector2i& position) override;
	virtual void setPosition(int x, int y) override;


	//Change the offset from position
	virtual void move(const sf::Vector2i& offset) override;
	virtual void move(int x, int y) override;

	//Use it to place the text in the middle of the rect
	void centerText();

	//Renders the text and the frame 
	virtual void render(sf::RenderTarget* target) override;


	// Func responsible for the stuff button does in update loop
	virtual Object* updateClickables(sf::Vector2f& mousePosition) override;


	//Gettery
	
	//Function returns color of the label's font 
	const sf::Color* getColorText() const;
	//Function returns the label's message in string format
	std::string getLabel();
	//Function returns the sfml text object used to render the text
	sf::Text* getText();
	//Function returns name of the file storing font
	const std::string& getFontName() const;
	short int getCharacterSize() const;

	//Settery
	//Function changes the color of the font using rgba format 
	void setColorText(int r, int g, int b, int a);
	void setCharacterSize(short int size);
	void setFont(const std::string& fontName);
	


	// Inherited via Object
	virtual void setScale(float x, float y) override;

	virtual std::pair<float, float> getScale() override;

};
