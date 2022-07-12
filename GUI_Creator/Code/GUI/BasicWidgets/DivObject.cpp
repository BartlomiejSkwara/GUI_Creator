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
/// Po usuniêciu obiektu pamiêta te¿ o wywaleniu  przypisanych mu dzieci
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
/// Funkcja sprawdza czy punkt znajduje siê w tym obiekcie 
/// </summary>
/// <param name="point">-koordynaty punktu</param>
/// <returns>-to czy warunek zosta³ spe³niony</returns>
bool DivObject::checkIfObjectContainsPoint(sf::Vector2f& point)
{
	sf::FloatRect temp = getGlobalBounds();
	bool temp2 = temp.contains(point.x,point.y);
	return  temp2;
		
}

/// <summary>
/// Funkcja renderuje obiekt i jego dzieci
/// </summary>
/// <param name="target">-obiekt na którym dokonane zostanie renderowanie</param>
void DivObject::render(sf::RenderTarget* target)
{
	target->draw(m_frame);
	for (auto object : m_renderableObjects) {
		object->render(target);
	}
}

/// <summary>
/// Funkcja odpowiada za wszystkie czynnoœci zwi¹zane z wciskalnymi obiektami i powinna byæ u¿ywana wy³¹cznie w g³ównej klasie Game w funkcji updateClickables
/// </summary>
/// <param name="mousePosition"></param>
///Zwraca glebie klikniecia
int DivObject::updateClickables(sf::Vector2f& mousePosition)
{
	//Zmiana dokonana w celu poprawienie zaznaczania obiektów w klasie GameSceneUIDesigner  ( od teraz gdy dwa obiekty s¹ na sobie zaznacza siê ten najwy¿ej)
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
/// <param name="objectType">-okreœla który z bazowuch typów jest poszukiwany zobacz (ContainerObject::O_ ... )</param>
/// <returns>-1 gdy nie znajdê obiektu</returns>
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
/// /// Szukanie jest wolne i prioretyzuje górne poziomy diva , zalecane jest usuwanie tych w³asnie wy¿szych poziomów w celu zniwelowania ga³ganiarstwa
/// W celu ograniczenia tegó¿ ga³ganiarstwa wprowadzam limit tego jak g³êboko mo¿e zajœæ rekurencja
/// Funkcja zaprzestanie rekurencyjnych dzia³añ gdy depth osi¹gnie wartoœæ 3
/// </summary>
/// <param name="ID">-id poszukiwanego obiektu</param>
/// <param name="depth">-pocz¹tkowa g³ebia rekurencji , bazowo pojawia siê tam 0 , podajac mniejsze wartoœci mo¿na zwiêkszyæ lub zmniejszyæ g³ebiê poszukiwañ</param>
/// <returns>-zwracana wartoœæ stanowi wyznacznik tego czy usuniêto poszukiwany obiekt</returns>
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

