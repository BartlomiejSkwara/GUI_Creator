#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

/// <summary>
/// Klasa odpowiedzialna za metody i zmienne wa¿ne dla 
/// klas które posiadaj¹ swego rodzaju powierzchniê czy te¿ t³o
/// </summary>
class Bordered 
{
protected:
    sf::RectangleShape m_frame;
public:
    Bordered();
    virtual ~Bordered();

    
    ///Gettery///

    /// Funkcja od pozyskiwania SFMLowego obiektu reprezentuj¹cego obramowanie wokó³ obiektu 
    const sf::FloatRect& getGlobalBounds() const;
    /// Funkcja zwraca wskaŸnik do koloru obramowania
    const sf::Color* getColorBorder() const;
    /// Funkcja zwraca wskaŸnik do koloru wype³nienia 
    const sf::Color* getColorFill() const;
    /// Funkcja zwraca gruboœæ obramowania
    int  getBorderThickness();


    /// /// ///




    ///Settery///
    
    /// Funkcja ustawia kolor obramowania (korzystaj¹c ze standardu rgba - red green blue alpha)
    void setColorBorder(int r, int g, int b, int a);
    /// Funkcja ustawia kolor wype³nienia (korzystaj¹c ze standardu rgba - red green blue alpha)
    void setColorFill(int r, int g, int b, int a);
    /// Funkcja ustawia pozycjê obiektu na wskazywan¹ przez SFMLowy wektor dwóch intów
    virtual void setPosition(const sf::Vector2i& position)  = 0;
    /// Funkcja ustawia pozycjê obiektu na wskazywan¹ przez dwa inty x i y 
    virtual void setPosition(int x, int y) = 0;
    /// Funkcja zmienia gruboœæ obramowanie 
    void setBorderThickness(int v);

    /// Funkcja zmienia przesuniêcie obiektu wzglêdem jego pozycji o wartoœæ wskazywan¹ przez SFMLowy wektor dwóch intów
    virtual void move(const sf::Vector2i& offset) = 0;
    /// Funkcja zmienia przesuniêcie obiektu wzglêdem jego pozycji o wartoœæ wskazywan¹ przez dwa inty x i y 
    virtual void move(int x, int y) = 0;
    
    /// /// ///
};

