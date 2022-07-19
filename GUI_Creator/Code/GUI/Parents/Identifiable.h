#pragma once
#include <string>
#include <iostream>

/// <summary>
/// Klasa po której powinny dziedziczyæ wszelkiego rodzaju obiekty wymagaj¹ce unikalnego ID
/// </summary>
class Identifiable
{
private:

	/// ID konkretnego obiektu
	std::string m_ID;
	/// Statyczna zmienna przechowuj¹ca id ostatniego obiektu , potrzebne w celu oszacowania kolejnego unikalnego ID
	static std::string generatedID;
public:

	
	/// Konstruktor automatycznie przydziela  unikalne ID
	Identifiable();
	
	Identifiable(const std::string ID) ; ///TODO przeka¿ przez referencjê, dodatkowo mo¿liwe ¿e ten konstruktor jest jednak do wywa³ki poniewa¿ chcemy mieæ UUID
	virtual ~Identifiable();


	///Gettery///

	/// Funkcja zwraca unikalne id danego obiektu
	const std::string& getID() const;
	
	/// /// ///
	
	/// Funkcja tworzy i zwraca nowe ID /// TODO zmieñ to na wskaŸniki
	static std::string generateID();

	/// Funkcja resetuje poprzednie ID do stanu z pocz¹tku istnienia klasy (korzystaj w momencie utworzenia nowej sceny)
	static void resetID();
};

