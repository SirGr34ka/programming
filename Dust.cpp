#include "Dust.h"
#include "Painter.h"

Dust::Dust( Point center , Velocity velocity ) :
center_{ center } , velocity_{ velocity } , radius{ 7.5 } , timeLeft{ 0.5 } , isAlive{ true }
{
    color = Color( 0.33 , 0.66 , 0.99 );

    clock.restart();
}

Velocity Dust::getVelocity() const
{
    return velocity_;
}

void Dust::draw( Painter& painter ) const
{
    painter.draw( center_ , radius , color );
}

void Dust::setCenter( const Point& center )
{
    center_ = center;
}

Point Dust::getCenter() const
{
    return center_;
}

bool Dust::getIsAlive() const
{
    return isAlive;
}

void Dust::update()
{
    double elapsedTime = clock.getElapsedTime().asSeconds();

    if (elapsedTime > timeLeft)
    {
        isAlive = false;
    }
}

double Dust::timer() const
{
    return timeLeft;
}