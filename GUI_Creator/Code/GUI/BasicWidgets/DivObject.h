#pragma once
#include "ButtonObject.h"
#include "../GUI_Creator/Code/GUI/Parents/Object.h"
#include <vector>
#include <iostream>
class DivObject : public Object
{
protected:
	


	//object finders
	int searchForObject(std::string& ID);
	int searchForDiv(std::string& ID);

	//Stored objects
	std::vector<Object*> m_Objects;
	//Stored DIVs
	std::vector<DivObject*> m_DIVs;


public:
	DivObject();

	//TODO rozdziel to na osobne funkcje
	DivObject(sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func = [](){});
	virtual ~DivObject();

	//Render the div and all of the objects inside of it 
	virtual void render(sf::RenderTarget* target) override;


	// Inherited via Clickable
	virtual Object* updateClickables(sf::Vector2f& mousePosition) override;

	


	//Functions responsible for changing postion of the div and objects inside of it	
	virtual void setPosition(const sf::Vector2i& position) override;
	virtual void setPosition(int x, int y) override;
	virtual void move(const sf::Vector2i& offset) override;


	//Function sets the dimensions of the container
	void setSize(int x, int y);

	// Inherited via Object
	virtual void move(int x, int y) override;






	///Div specific
	const std::vector<Object*>* getObjectVector()const;


	//Functions responsible for assigning new objects to the DIV
	void addObject(Object* object);
	void addDiv(DivObject* div);

	//Functions responsible for removing object from the DIV
	bool removeObject(std::string& ID, int depth = 0);

};

