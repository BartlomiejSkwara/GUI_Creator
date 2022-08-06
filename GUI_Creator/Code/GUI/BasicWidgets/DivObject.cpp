#include "DivObject.h"



/// <summary>
/// Function finds and returns  the object you are looking for
/// </summary>
/// <param name="soughtObj">adress in memory of sought obj</param>
/// <param name="retrieve">if set to true sought element will be removed from the object containing it (but it will still exist in memory)</param>
/// <returns></returns>
Object* DivObject::find(Object* soughtObj, FindMode fm)
{
	static Object* objHolder = nullptr;
	for (auto i = m_Objects.begin(); i != m_Objects.end(); i++) {
		objHolder = (*i)->find(soughtObj, fm);
		if (objHolder) {
			switch(fm) {
			
			case FindMode::FIND_AND_MOVE_DOWN:
				*i = *(i - 1);
				*(i - 1) = objHolder;
				break;
			case FindMode::FIND_AND_MOVE_UP:
				*i = *(i + 1);
				*(i + 1) = objHolder;
				break;
			case FindMode::FIND_AND_REMOVE:
				*i = *(m_Objects.end() - 1);
				m_Objects.pop_back();
					break;
			
			default:
				break;
			}
			
			
			return nullptr;
		}
	}
	
	return Object::find(soughtObj);
}

DivObject::DivObject(sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func, float scale)
	:Object()
{
	m_frame.setFillColor(color);
	m_frame.setSize(sf::Vector2f(sizeX, sizeY));
	m_frame.setPosition(sf::Vector2f(posX, posY));
	setScale(scale, scale);

}

/// <summary>
/// Po usuniêciu obiektu pamiêta te¿ o wywaleniu  przypisanych mu dzieci
/// </summary>
DivObject::~DivObject()
{
	for (auto object : m_Objects)
	{
		delete object;
	}
}




/// <summary>
/// Funkcja renderuje obiekt i jego dzieci
/// </summary>
/// <param name="target">-obiekt na którym dokonane zostanie renderowanie</param>
void DivObject::render(sf::RenderTarget* target)
{
	target->draw(m_frame);
	for (auto object : m_Objects) {
		object->render(target);
	}
}



/// <summary>
/// Function checks if cursor is inside of any of the objects div contains
/// Be aware that the function won't check if the cursor is inside of the div 
/// </summary>
/// <param name="mousePosition"></param>
/// <returns>Depth of the click (how many other div's it had to go through to reach the clicked element )</returns>
Object* DivObject::updateClickables(sf::Vector2f& mousePosition)
{
	//Zmiana dokonana w celu poprawienie zaznaczania obiektów w klasie GameSceneUIDesigner  ( od teraz gdy dwa obiekty s¹ na sobie zaznacza siê ten najwy¿ej)
	for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it){
	//for (auto object : m_Clickables) {
		if ((* it)->checkIfObjectContainsPoint(mousePosition)) {
			return (* it)->updateClickables(mousePosition);
			
		}
	}

	return this;
}












void DivObject::setScale(float x, float y)
{
	m_frame.setScale(x,y);
}

std::pair<float,float> DivObject::getScale()
{
	return { m_frame.getScale().x,m_frame.getScale().y };
}

//TODO  don't  call mouse position view so much
bool DivObject::handleEvent(Event& event)
{
	
	
	switch (event.getType())
	{
		

	case EventType::MouseLPMClickObject:
		if (checkIfObjectContainsPoint(MouseInput::getMouseInf()->mousePositionView)) {
			if (m_Objects.size() == 0)
			{
				runEvent(event);
				return true;
			}
			for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it) {
				//for (auto object : m_Clickables) {

				if ((*it)->handleEvent(event))
				{
					return true;
				}


			}
			runEvent(event);
			return true;
		}
		break;

	case EventType::MouseLPMClickImage: case EventType::MouseLPMClickText:
		if (checkIfObjectContainsPoint(MouseInput::getMouseInf()->mousePositionView)) {
			//Zmiana dokonana w celu poprawienie zaznaczania obiektów w klasie GameSceneUIDesigner  ( od teraz gdy dwa obiekty s¹ na sobie zaznacza siê ten najwy¿ej)

			for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it) {
				//for (auto object : m_Clickables) {

				if ((*it)->handleEvent(event))
				{
					return true;
				}



			}
			//runEvent(event);
			return false;
		}
		break;
		
	case EventType::MouseLPMClickDiv:
		if (checkIfObjectContainsPoint(MouseInput::getMouseInf()->mousePositionView)) {
			for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it) {
				//for (auto object : m_Clickables) {
				if ((*it)->handleEvent(event)) {
					return true;
				}

			}
			runEvent(event);
			return (m_Objects.size()>0)?true:false;
		}
		break;

		
	default:
		break;
	}
	


	
	return false;
	
	

}

bool DivObject::handleEventChildrenOnly(Event& event)
{
	for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it) {

		if ((*it)->handleEvent(event))
		{
			return true;
		}
	


	}
	return false;

	
}

void DivObject::setPosition(const sf::Vector2i& position)
{
	setPosition(position.x,position.y);
}

void DivObject::setPosition(int x, int y)
{
	for (auto object : m_Objects) {
		object->move((int)(x - m_frame.getPosition().x), (int)(y - m_frame.getPosition().y));
	}

	float thick = m_frame.getOutlineThickness();
	m_frame.setPosition(x + thick, y + thick);

}


void DivObject::move(const sf::Vector2i& offset)
{
	move(offset.x, offset.y);
	
}



void DivObject::move(int x, int y)
{
	m_frame.move((float)x, (float)y);

	for (auto object : m_Objects) {
		object->move(x,y);
	}
}


const std::vector<Object*>* DivObject::getObjectVector() const
{
	return &m_Objects;
}

void DivObject::addObject(Object* object)
{
	m_Objects.push_back(object);
}




