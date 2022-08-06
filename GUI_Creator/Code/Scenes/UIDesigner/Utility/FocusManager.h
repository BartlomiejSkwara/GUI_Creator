#pragma once
#include <iostream>
#include "SFML/Graphics/CircleShape.hpp"
#include "../GUI_Creator/Code/GUI/BasicWidgets/DivObject.h"

/// <summary>
/// Singleton used to manage which objects are selected 
/// and selections style
/// </summary>        FocusManager::getFocusManager();
class FocusManager
{
public:

	FocusManager();


	//Gettery
	

	
	float getIndicatorSize();
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
	void addChildSelectionSignifier(Object* focalElement);


	FocusManager(FocusManager& selMan) = delete;
	void operator=(const FocusManager&) = delete;
	
	void clearChildren();
	
private:
	

	sf::CircleShape m_focusSignifier;
	sf::CircleShape m_childFocusSignifier;
	std::vector<sf::Vector2f> m_childPositions;

	

	bool im_showMainSelection = true;
	bool im_showChildSelection = false;


};

