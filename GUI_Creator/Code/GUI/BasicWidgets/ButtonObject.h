#pragma once
#include "../RenderableObject.h"
#include "../ClickableObject.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

//TODO dodaj jaki� konstruktorek bez argument�w :>
class ButtonObject : public RenderableObject , public ClickableObject
{

private:
	//Ramka i napis w przycisku
	sf::RectangleShape m_frame;
	sf::Text m_text;
public:

	ButtonObject(std::string ID, sf::Font& font,std::string label, float positionX, float positionY, const std::function<void()>& func = [](){}, float sizeX = 100, float sizeY = 30, int charSize = 20, float scale = 1.f);
	virtual ~ButtonObject();

	//Inicjalizacja
	void initText(sf::Font& font, const std::string& label);
	void initText(const std::string& label);
	


	//Inicjalizacja - pozycja

	virtual void setPosition(const sf::Vector2i& position) override;
	virtual void setPosition(int x, int y) override;
	virtual void move(const sf::Vector2f& offset) override;
	void centerText();


	// Inherited via RenderableObject

	virtual const sf::FloatRect& getGlobalBounds() const override;

	virtual bool checkIfObjectContainsPoint(sf::Vector2f& point) override;

	virtual void render(sf::RenderTarget* target) override;


	// Inherited via ClickableObject
	virtual int updateClickables(sf::Vector2f& mousePosition) override;


	//Gettery
	virtual const sf::Color* getColorBorder() const override;
	virtual const sf::Color* getColorFill() const override;

	const sf::Color* getColorText() const;
	std::string getLabel();
	sf::Text* getText();
	
	//Settery
	virtual void setColorBorder(int r,int g, int b, int a) override;
	virtual void setColorFill(int r, int g, int b, int a) override;
	void setColorText(int r, int g, int b, int a);





	// Inherited via RenderableObject
	virtual int getBorderThickness() override;

	virtual void setBorderThickness(int v) override;


	// Inherited via RenderableObject
	virtual float getScale() override;

	virtual void setScale(float s) override;

};
