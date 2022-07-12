#pragma once
#include "ButtonObject.h"
#include "../ContainerObject.h"
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
class DivObject : public RenderableObject, public ClickableObject, public ContainerObject
{
private:
	//Obiekty które zostan¹ renderowane na ekranie 
	std::vector<RenderableObject*> m_renderableObjects;
	//Obiekty które uczestnicz¹ w teœcie na bycie klikniêtym
	std::vector<ClickableObject*> m_clickableObjects;
	//Obiekty które przechowuj¹ inne obiekty
	std::vector<ContainerObject*> m_containerObjects;
	//Wymiary i pozycja diva (konteneru)
	sf::RectangleShape m_frame;
public:
	DivObject();
	//TODO rozdziel to na osobne funkcje
	DivObject(std::string ID, sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func = [](){}); ///TODO  ten string i referencja 
	virtual ~DivObject();


	// Inherited via RenderableObject
	virtual const sf::FloatRect & getGlobalBounds() const override;

	virtual bool checkIfObjectContainsPoint(sf::Vector2f& point) override;

	virtual void render(sf::RenderTarget* target) override;


	// Inherited via ClickableObject
	virtual int updateClickables(sf::Vector2f& mousePosition) override;


	// Inherited via ContainerObject
	//Poszukiwaczki

	virtual int searchForObject(std::string & ID, OBJECT_TYPE objectType) override;

	//Dodawaczki :>

	void addDivObject(DivObject* object);
	void addButtonObject(ButtonObject* object);
	virtual void addRenderableObject(RenderableObject* object) override;
	virtual void addClickableObject(ClickableObject* object) override;
	virtual void addContainerObject(ContainerObject* object) override;
	//Usuwaczka

	virtual bool removeObject(std::string & ID,int depth=0) override;


	//Przesuwaczki 	
	virtual void setPosition(const sf::Vector2i& position) override;
	virtual void setPosition(int x, int y) override;
	virtual void move(const sf::Vector2f& offset) override;


	// Inherited via RenderableObject
	virtual int getBorderThickness() override;

	virtual void setBorderThickness(int v) override;

};

