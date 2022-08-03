#pragma once
#include <string>
#include <iostream>

/// <summary>
/// Klasa po kt�rej powinny dziedziczy� wszelkiego rodzaju obiekty wymagaj�ce unikalnego ID
/// </summary>
class Identifiable
{
private:

	/// ID konkretnego obiektu
	std::string m_ID;
	/// Statyczna zmienna przechowuj�ca id ostatniego obiektu , potrzebne w celu oszacowania kolejnego unikalnego ID
	static std::string generatedID;
public:

	
	/// Konstruktor automatycznie przydziela  unikalne ID
	Identifiable();
	
	Identifiable(const std::string ID) ; ///TODO przeka� przez referencj�, dodatkowo mo�liwe �e ten konstruktor jest jednak do wywa�ki poniewa� chcemy mie� UUID
	virtual ~Identifiable();


	///Gettery///

	/// Funkcja zwraca unikalne id danego obiektu
	const std::string& getID() const;
	
	/// /// ///
	
	/// Funkcja tworzy i zwraca nowe ID /// TODO zmie� to na wska�niki
	static std::string generateID();

	/// Funkcja resetuje poprzednie ID do stanu z pocz�tku istnienia klasy (korzystaj w momencie utworzenia nowej sceny)
	static void resetID();
};

