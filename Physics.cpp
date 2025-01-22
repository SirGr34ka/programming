#include "Physics.h"

double dot(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

Physics::Physics(double timePerTick) : timePerTick{timePerTick} {}

void Physics::setWorldBox(const Point& topLeft, const Point& bottomRight) {
    this->topLeft = topLeft;
    this->bottomRight = bottomRight;
}

void Physics::update( std::vector<Ball>& balls , std::vector< Dust >& dusts , const size_t ticks ) const {

    for (size_t i = 0; i < ticks; ++i) {
        move( balls );
        move( dusts );
        collideWithBox( balls );
        collideBalls( balls , dusts );
    }
}

void Physics::collideBalls( std::vector<Ball>& balls , std::vector< Dust >& dusts ) const {
    for (auto a = balls.begin(); a != balls.end(); ++a) {
        if ( a->getIsCollidable() )
        {
            for (auto b = std::next(a); b != balls.end(); ++b) {
                const double distanceBetweenCenters2 =
                    distance2(a->getCenter(), b->getCenter());
                const double collisionDistance = a->getRadius() + b->getRadius();
                const double collisionDistance2 =
                    collisionDistance * collisionDistance;

                if ( ( distanceBetweenCenters2 < collisionDistance2 ) && ( b->getIsCollidable() ) )
                {
                    Dust dust1( a->getCenter() , Velocity( -500 , 60 ) );
                    Dust dust2( b->getCenter() , Velocity( 500 , 60 ) );
                    Dust dust3( a->getCenter() , Velocity( -500 , 30 ) );
                    Dust dust4( b->getCenter() , Velocity( 500 , 30 ) );
                    Dust dust5( a->getCenter() , Velocity( -500 , 45 ) );
                    Dust dust6( b->getCenter() , Velocity( 500 , 45 ) );
                    Dust dust7( a->getCenter() , Velocity( -500 , 90 ) );
                    Dust dust8( b->getCenter() , Velocity( 500 , 90 ) );
                    dusts.push_back( dust1 );
                    dusts.push_back( dust2 );
                    dusts.push_back( dust3 );
                    dusts.push_back( dust4 );
                    dusts.push_back( dust5 );
                    dusts.push_back( dust6 );
                    dusts.push_back( dust7 );
                    dusts.push_back( dust8 );

                    processCollision(*a, *b, distanceBetweenCenters2);
                }
            }
        }
    }
}

void Physics::collideWithBox(std::vector<Ball>& balls) const {
    for (Ball& ball : balls) {
        if ( ball.getIsCollidable() )
        {
            const Point p = ball.getCenter();
            const double r = ball.getRadius();
            // определяет, находится ли v в диапазоне (lo, hi) (не включая границы)
            auto isOutOfRange = [](double v, double lo, double hi) {
                return v < lo || v > hi;
            };

            if (isOutOfRange(p.x, topLeft.x + r, bottomRight.x - r)) {
                Point vector = ball.getVelocity().vector();
                vector.x = -vector.x;
                ball.setVelocity(vector);
            } else if (isOutOfRange(p.y, topLeft.y + r, bottomRight.y - r)) {
                Point vector = ball.getVelocity().vector();
                vector.y = -vector.y;
                ball.setVelocity(vector);
            }
        }
    }
}

template< typename T >
void Physics::move( std::vector< T >& objects ) const {
    for ( T& object : objects ) {
        Point newPos =
            object.getCenter() + object.getVelocity().vector() * timePerTick;
        object.setCenter(newPos);
    }
}

void Physics::processCollision(Ball& a, Ball& b,
                               double distanceBetweenCenters2) const {
    if ( a.getIsCollidable() && b.getIsCollidable() )
    {
        // нормированный вектор столкновения
        const Point normal =
            (b.getCenter() - a.getCenter()) / std::sqrt(distanceBetweenCenters2);

        // получаем скорость в векторном виде
        const Point aV = a.getVelocity().vector();
        const Point bV = b.getVelocity().vector();

        // коэффициент p учитывает скорость обоих мячей
        const double p =
            2 * (dot(aV, normal) - dot(bV, normal)) / (a.getMass() + b.getMass());

        // задаем новые скорости мячей после столкновения
        a.setVelocity(Velocity(aV - normal * p * a.getMass()));
        b.setVelocity(Velocity(bV + normal * p * b.getMass()));
    }
}
