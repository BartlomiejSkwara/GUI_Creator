#include "PWW_Object.h"

PWW_Object::PWW_Object(Object* editedObject)
	:selectManager(SelectionManager::getSelectionManager()), resourceManager(ResourceManager::getResourceManager())
{
    m_size[0] = editedObject->getGlobalBounds().width;
    m_size[1] = editedObject->getGlobalBounds().height;

    m_position[0] = editedObject->getGlobalBounds().left;
    m_position[1] = editedObject->getGlobalBounds().top;

    m_outline_size = editedObject->getBorderThickness();

    m_outlineColor[0] = (float)editedObject->getColorBorder()->r / 255;
    m_outlineColor[1] = (float)editedObject->getColorBorder()->g / 255;
    m_outlineColor[2] = (float)editedObject->getColorBorder()->b / 255;
    m_outlineColor[3] = (float)editedObject->getColorBorder()->a / 255;

    m_fillColor[0] = (float)editedObject->getColorFill()->r / 255;
    m_fillColor[1] = (float)editedObject->getColorFill()->g / 255;
    m_fillColor[2] = (float)editedObject->getColorFill()->b / 255;
    m_fillColor[3] = (float)editedObject->getColorFill()->a / 255;

     m_scale[0] = editedObject->getScale().first;
     m_scale[1] = editedObject->getScale().second;
}

