#pragma once
#include <iostream>
#include "SFML/Graphics/CircleShape.hpp"
#include "../GUI_Creator/Code/GUI/RenderableObject.h"
#include "../GUI_Creator/Code/GUI/ImGuiWrappers/ParamWindowWrapper.h"
/// <summary>
/// Singleton used to manage which objects are selected 
/// and selections style
/// </summary>        SelectionManager::getSelectionManager();
class SelectionManager
{
public:

	static SelectionManager* getSelectionManager();


	//Gettery
	float getIndicatorSize();
	bool isObjectFocused();
	RenderableObject* getFocusedElement();
	ParamWindowWrapper* getSelectedElement();

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
	void changeFocus(RenderableObject* newFocus, ParamWindowWrapper* newIm_selectedElement);
	void loseFocus();
	void addChildSelectionSignifier(RenderableObject* focalElement);


	SelectionManager(SelectionManager& selMan) = delete;
	void operator=(const SelectionManager&) = delete;
	
	
private:
	SelectionManager();
	static SelectionManager* instance;


	sf::CircleShape m_focusSignifier;
	sf::CircleShape m_childFocusSignifier;
	std::vector<sf::Vector2f> m_childPositions;

	bool m_objectIsFocused;
	
	
	//Focus related
	//Used when taking data out of selected obj
	RenderableObject* m_focusedElement;
	//Used when displaying imGui param window
	ParamWindowWrapper* im_selectedElement;
	

	bool im_showMainSelection = true;
	bool im_showChildSelection = false;


};

