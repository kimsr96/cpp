#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;
    
    public:
        Point();
        Point(const Fixed &F_x, const Fixed &F_y);
        ~Point();
        Point(const Point &copy);
        Point &operator=(const Point &copy);
        const Fixed &getX(void) const;
        const Fixed &getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif 