#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
    Velocity velocity_;
    Point center_;
    Color color_;
    double radius_;
    double mass;
    bool isCollidable_;

public:
    Ball( const Velocity& velocity , const Color& color , const Point& center , const double radius , const bool isCollidable );
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getIsCollidable() const;
};
