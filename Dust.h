#pragma once
#include "Point.h"
#include "Velocity.h"
#include "Color.h"
#include "Painter.h"
#include <SFML/Graphics.hpp>

class Dust 
{
    Velocity velocity_;
    Color color;
    Point center_;
    double radius;
    double timeLeft;
    bool isAlive;
    sf::Clock clock;

    public:

    Dust( Point center , Velocity velocity );
    Velocity getVelocity() const;
    void draw(Painter &painter) const;
    void setCenter(const Point& _center);
    Point getCenter() const;
    bool getIsAlive() const;
    double timer() const;
    void update();
};