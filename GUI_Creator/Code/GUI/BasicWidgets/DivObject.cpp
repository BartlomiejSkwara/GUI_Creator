#include "DivObject.h"

DivObject::DivObject()
{
}


DivObject::DivObject(sf::Color color, float posX, float posY, float sizeX, float sizeY, const std::function<void()>& func)
	:Object(func)
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
	for (auto object : m_Objects)
	{
		delete object;
	}
}




/// <summary>
/// Funkcja renderuje obiekt i jego dzieci
/// </summary>
/// <param name="target">-obiekt na kt�rym dokonane zostanie renderowanie</param>
void DivObject::render(sf::RenderTarget* target)
{
	target->draw(m_frame);
	for (auto object : m_Objects) {
		object->render(target);
	}
}



/// <summary>
/// Funkcja odpowiada za wszystkie czynno�ci zwi�zane z wciskalnymi obiektami i powinna 
/// by� u�ywana wy��cznie w g��wnej klasie Game w funkcji updateClickables
/// </summary>
/// <param name="mousePosition"></param>
/// <returns>Depth of the click (how many other div's it had to go through to reach the clicked element )</returns>
int DivObject::updateClickables(sf::Vector2f& mousePosition)
{
	//Zmiana dokonana w celu poprawienie zaznaczania obiekt�w w klasie GameSceneUIDesigner  ( od teraz gdy dwa obiekty s� na sobie zaznacza si� ten najwy�ej)
	for (std::vector<Object*>::reverse_iterator it = m_Objects.rbegin(); it != m_Objects.rend(); ++it){
	//for (auto object : m_Clickables) {
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
/// <param name="objectType">-okre�la kt�ry z bazowuch typ�w jest poszukiwany zobacz (Container::O_ ... )</param>
/// <returns>-1 gdy nie znajd� obiektu</returns>
int DivObject::searchForObject(std::string & ID)
{
	
	for (auto i = m_Objects.begin(); i < m_Objects.end(); i++)
	{
		if ((*i)->getID() == ID)
		{
			return i - m_Objects.begin();
		}
	}
	return -1;
}

int DivObject::searchForDiv(std::string& ID)
{
	for (auto i = m_DIVs.begin(); i < m_DIVs.end(); i++)
	{
		if ((*i)->getID() == ID)
		{
			return i - m_DIVs.begin();
		}
	}
	return -1;
}






//TODO Niepokoi mnie dzia�anie depth mo�e trzeba je zamieni� na static ?
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
	static int objectPosition = searchForObject(ID);
	if (objectPosition == -1) {
		for (auto* obj: m_DIVs) {
			bool found = obj->removeObject(ID,depth+1);
			if (found == true) {
				return true;
			}
		}
		return false;
	}

	Object* temp = m_Objects.at(objectPosition);
	m_Objects.erase(m_Objects.begin() + objectPosition);

	objectPosition = searchForDiv(ID);
	m_DIVs.erase(m_DIVs.begin() + objectPosition);
	
	delete temp;

	return true;
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

void DivObject::setSize(int x, int y)
{
	m_frame.setSize(sf::Vector2f((float)x,(float)y));
}

void DivObject::move(int x, int y)
{
	m_frame.move((float)x, (float)y);

	for (auto object : m_DIVs) {
		object->move(x,y);
	}
}


void DivObject::addObject(Object* object)
{
	m_Objects.push_back(object);
}

void DivObject::addDiv(DivObject* div)
{
	m_Objects.push_back(div);
	m_DIVs.push_back(div);
}



