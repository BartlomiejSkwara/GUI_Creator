#include "DivObject.h"

DivObject::DivObject()
{
}

/// <summary>
/// 
/// </summary>
/// <param name="ID"></param>
/// <param name="func"></param>
/// <param name="color"></param>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
DivObject::DivObject(std::string ID ,sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func)
	:IdentifiableObject(ID), ClickableObject(func)
{
	m_frame.setFillColor(color);
	m_frame.setSize(sf::Vector2f(sizeX, sizeY));
	m_frame.setPosition(sf::Vector2f(posX, posY));
}

/// <summary>
/// Po usuni�ciu obiektu pami�ta te� o wywaleniu  przypisanych mu dzieci
/// </summary>
DivObject::~DivObject()
{
	for (auto object : m_renderableObjects)
	{
		delete object;
	}
}

/// <summary>
/// Funkcja zwraca wymiary obiektu
/// </summary>
/// <returns></returns>
const sf::FloatRect & DivObject::getGlobalBounds() const
{
	return  m_frame.getGlobalBounds();
}

/// <summary>
/// Funkcja sprawdza czy punkt znajduje si� w tym obiekcie 
/// </summary>
/// <param name="point">-koordynaty punktu</param>
/// <returns>-to czy warunek zosta� spe�niony</returns>
bool DivObject::checkIfObjectContainsPoint(sf::Vector2f& point)
{
	sf::FloatRect temp = getGlobalBounds();
	bool temp2 = temp.contains(point.x,point.y);
	return  temp2;
		
}

/// <summary>
/// Funkcja renderuje obiekt i jego dzieci
/// </summary>
/// <param name="target">-obiekt na kt�rym dokonane zostanie renderowanie</param>
void DivObject::render(sf::RenderTarget* target)
{
	target->draw(m_frame);
	for (auto object : m_renderableObjects) {
		object->render(target);
	}
}

/// <summary>
/// Funkcja odpowiada za wszystkie czynno�ci zwi�zane z wciskalnymi obiektami i powinna by� u�ywana wy��cznie w g��wnej klasie Game w funkcji updateClickables
/// </summary>
/// <param name="mousePosition"></param>
///Zwraca glebie klikniecia
int DivObject::updateClickables(sf::Vector2f& mousePosition)
{
	//Zmiana dokonana w celu poprawienie zaznaczania obiekt�w w klasie GameSceneUIDesigner  ( od teraz gdy dwa obiekty s� na sobie zaznacza si� ten najwy�ej)
	for (std::vector<ClickableObject*>::reverse_iterator it = m_clickableObjects.rbegin(); it != m_clickableObjects.rend(); ++it){
	//for (auto object : m_clickableObjects) {
		if ((* it)->checkIfObjectContainsPoint(mousePosition)) {
			return 1 + (* it)->updateClickables(mousePosition);
			
		}
	}
	runEvent();
	return 1;
}

/// <summary>
/// Szuka obiektu po ID w danym kontenerze
/// </summary>
/// <param name="ID">-Id poszukiwanego obiektu</param>
/// <param name="objectType">-okre�la kt�ry z bazowuch typ�w jest poszukiwany zobacz (ContainerObject::O_ ... )</param>
/// <returns>-1 gdy nie znajd� obiektu</returns>
int DivObject::searchForObject(std::string & ID, OBJECT_TYPE objectType)
{
	if (objectType & ContainerObject::O_RENDERABLE)
	{
		for (auto i = m_renderableObjects.begin(); i < m_renderableObjects.end(); i++)
		{
			std::string str = (*i)->getID();
			if ((*i)->getID() == ID)
			{
				return i - m_renderableObjects.begin();
			}
		}
	}
	else if (objectType & ContainerObject::O_CLICKABLE)
	{
		for (auto i = m_clickableObjects.begin(); i < m_clickableObjects.end(); i++)
		{
			if ((*i)->getID() == ID)
			{
				return i - m_clickableObjects.begin();
			}
		}
	}
	else if (objectType & ContainerObject::O_CONTAINER)
	{
		for (auto i = m_containerObjects.begin(); i < m_containerObjects.end(); i++)
		{
			if ((*i)->getID() == ID)
			{
				return i - m_containerObjects.begin();
			}
		}
	}
	
	return -1;
}







/// <summary>
/// /// Szukanie jest wolne i prioretyzuje g�rne poziomy diva , zalecane jest usuwanie tych w�asnie wy�szych poziom�w w celu zniwelowania ga�ganiarstwa
/// W celu ograniczenia teg� ga�ganiarstwa wprowadzam limit tego jak g��boko mo�e zaj�� rekurencja
/// Funkcja zaprzestanie rekurencyjnych dzia�a� gdy depth osi�gnie warto�� 3
/// </summary>
/// <param name="ID">-id poszukiwanego obiektu</param>
/// <param name="depth">-pocz�tkowa g�ebia rekurencji , bazowo pojawia si� tam 0 , podajac mniejsze warto�ci mo�na zwi�kszy� lub zmniejszy� g�ebi� poszukiwa�</param>
/// <returns>-zwracana warto�� stanowi wyznacznik tego czy usuni�to poszukiwany obiekt</returns>
bool DivObject::removeObject(std::string & ID,int depth)
{	

	if (depth >= 3) {
		return false;
	}
	int objectPosition = searchForObject(ID, ContainerObject::O_RENDERABLE);
	if (objectPosition == -1) {
		for (auto* cont : m_containerObjects) {
			bool found = removeObject(ID,depth+1);
			if (found == true) {
				return true;
			}
		}
		return false;
	}

	RenderableObject* temp = m_renderableObjects.at(objectPosition);

	//Kasuj renderable
	m_renderableObjects.erase(m_renderableObjects.begin() + objectPosition);

	//Kasuj clickable
	objectPosition = searchForObject(ID, ContainerObject::O_CLICKABLE);
	if (objectPosition!=-1)
		m_clickableObjects.erase(m_clickableObjects.begin() + objectPosition);

	//Kasuj kontener
	objectPosition = searchForObject(ID, ContainerObject::O_CONTAINER);
	if (objectPosition != -1)
		m_containerObjects.erase(m_containerObjects.begin() + objectPosition);

	delete temp;

	return true;
}

void DivObject::setPosition(const sf::Vector2i& position)
{
	setPosition(position.x,position.y);
}

void DivObject::setPosition(int x, int y)
{
	for (auto object : m_renderableObjects) {
		object->move(sf::Vector2f(x - m_frame.getPosition().x, y - m_frame.getPosition().y));
	}

	float thick = m_frame.getOutlineThickness();
	m_frame.setPosition(x + thick, y + thick);

}


void DivObject::move(const sf::Vector2f& offset)
{
	m_frame.move(offset);

	for (auto object : m_renderableObjects) {
		object->move(offset);
	}
}

/// <summary>
/// Funkcja pomaga w szybszysm dodaniu diva
/// </summary>
/// <param name="object"></param>
void DivObject::addDivObject(DivObject * object)
{
	addRenderableObject(object);
	addClickableObject(object);
	addContainerObject(object);
}

void DivObject::addButtonObject(ButtonObject* object)
{
	addRenderableObject(object);
	addClickableObject(object);
}

void DivObject::addRenderableObject(RenderableObject* object)
{
	m_renderableObjects.push_back(object);
}

void DivObject::addClickableObject(ClickableObject* object)
{
	m_clickableObjects.push_back(object);
}

void DivObject::addContainerObject(ContainerObject* object)
{
	m_containerObjects.push_back(object);
}

