#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0){
};

Point::Point(const Fixed &F_x, const Fixed &F_y) : x(F_x), y(F_y){
};

Point::~Point(){    
};

Point::Point(const Point &copy) : x(copy.x), y(copy.y){
};

Point &Point::operator=(const Point& ){
    return (*this);
};

const Fixed &Point::getX(void) const{
    return (x);
};

const Fixed &Point::getY(void) const{
    return (y);
};


