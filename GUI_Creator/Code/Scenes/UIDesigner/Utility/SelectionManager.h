#pragma once
#include <iostream>
#include "SFML/Graphics/CircleShape.hpp"
#include "../GUI_Creator/Code/GUI/BasicWidgets/DivObject.h"

/// <summary>
/// Singleton used to manage which objects are selected 
/// and selections style
/// </summary>        SelectionManager::getSelectionManager();
class SelectionManager
{
public:

	


	//Gettery
	
	// This one can create the singleton
	static SelectionManager* getSelectionManager();

	//
	float getIndicatorSize();
	bool isObjectFocused();
	Object* getFocusedElement();

	sf::CircleShape* getFocusSignifier();




	bool isShowingMainSelection();
	bool isShowingChildSelection();

	//Settery
	void setIndicatorSize(float size);
	void setShowMainSelection(bool val);
	void setShowChildSelection(bool val);

	//Rendering 
	void renderFocusSignifiers(sf::RenderTarget* target);

	//Focus related 
	void changeFocus(Object* newFocus);
	void loseFocus();
	void addChildSelectionSignifier(Object* focalElement);


	SelectionManager(SelectionManager& selMan) = delete;
	void operator=(const SelectionManager&) = delete;
	
	void clearChildren();
	
private:
	SelectionManager();
	static SelectionManager* instance;


	sf::CircleShape m_focusSignifier;
	sf::CircleShape m_childFocusSignifier;
	std::vector<sf::Vector2f> m_childPositions;

	bool m_objectIsFocused;
	
	
	//Focus related
	//Used when taking data out of selected obj
	Object* m_focusedElement;

	bool im_showMainSelection = true;
	bool im_showChildSelection = false;


};

