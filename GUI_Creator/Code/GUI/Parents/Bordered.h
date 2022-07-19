#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

/// <summary>
/// Klasa odpowiedzialna za metody i zmienne wa�ne dla 
/// klas kt�re posiadaj� swego rodzaju powierzchni� czy te� t�o
/// </summary>
class Bordered 
{
protected:
    sf::RectangleShape m_frame;
public:
    Bordered();
    virtual ~Bordered();

    
    ///Gettery///

    /// Funkcja od pozyskiwania SFMLowego obiektu reprezentuj�cego obramowanie wok� obiektu 
    const sf::FloatRect& getGlobalBounds() const;
    /// Funkcja zwraca wska�nik do koloru obramowania
    const sf::Color* getColorBorder() const;
    /// Funkcja zwraca wska�nik do koloru wype�nienia 
    const sf::Color* getColorFill() const;
    /// Funkcja zwraca grubo�� obramowania
    int  getBorderThickness();


    /// /// ///




    ///Settery///
    
    /// Funkcja ustawia kolor obramowania (korzystaj�c ze standardu rgba - red green blue alpha)
    void setColorBorder(int r, int g, int b, int a);
    /// Funkcja ustawia kolor wype�nienia (korzystaj�c ze standardu rgba - red green blue alpha)
    void setColorFill(int r, int g, int b, int a);
    /// Funkcja ustawia pozycj� obiektu na wskazywan� przez SFMLowy wektor dw�ch int�w
    virtual void setPosition(const sf::Vector2i& position)  = 0;
    /// Funkcja ustawia pozycj� obiektu na wskazywan� przez dwa inty x i y 
    virtual void setPosition(int x, int y) = 0;
    /// Funkcja zmienia grubo�� obramowanie 
    void setBorderThickness(int v);

    /// Funkcja zmienia przesuni�cie obiektu wzgl�dem jego pozycji o warto�� wskazywan� przez SFMLowy wektor dw�ch int�w
    virtual void move(const sf::Vector2i& offset) = 0;
    /// Funkcja zmienia przesuni�cie obiektu wzgl�dem jego pozycji o warto�� wskazywan� przez dwa inty x i y 
    virtual void move(int x, int y) = 0;
    
    /// /// ///
};

