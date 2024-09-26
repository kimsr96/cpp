#include "Point.hpp"

bool cross(Point &a, Point &b){
    return (a.getX() * b.getY() - a.getY() * b.getX() > 0);
};

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Point pa(a.getX() - point.getX(), a.getY() - point.getY());
    Point pb(b.getX() - point.getX(), b.getY() - point.getY());
    Point pc(c.getX() - point.getX(), c.getY() - point.getY());

    bool papc = cross(pa, pc);
    bool pcpb = cross(pc, pb);
    bool pbpa = cross(pb, pa);

    if (papc == pcpb && papc == pbpa)
        return (true);
    else
        return (false);
};
