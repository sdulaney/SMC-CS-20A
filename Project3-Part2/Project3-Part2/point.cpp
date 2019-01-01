#include"point.h"

Point::Point():m_x(0), m_y(0) {}

Point::Point(int x, int y): m_x(x), m_y(y) {}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}
void Point::set(int x, int y) {
    m_x = x;
    m_y = y;
}
bool Point::operator==(const Point& other) {
    return (m_x == other.m_x && m_y == other.m_y);
}



std::ostream & operator<<(std::ostream &os, const Point& p) {
    return os << "(" << p.m_x <<","<<p.m_y<<")";
}

Point operator+ (const Point &lhs, const Point &rhs) {
    Point p(lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
    return p;
}
Point operator- (const Point &lhs, const Point &rhs) {
    Point p(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
    return p;
}

double sqrDist(const Point &p1, const Point &p2) {
    
    double x0 = p1.getX();
    double x1 = p2.getX();
    double y0 = p1.getY();
    double y1 = p2.getY();
    double dist = (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1);
    return dist;
}
