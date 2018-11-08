#ifndef POINT_H
#define POINT_H
#include<ostream>

// Points on 2d grid
class Point {
    // Overloaded operators for convenience.  You must be careful with
    // friend functions if abused you can easily violate encapsulation.
    // Functions that can be made friends are tightly related to concept
    // of the object.  Overloading operators are prime examples of such
    // functions.
    friend std::ostream & operator<<(std::ostream &os, const Point& p);
    friend Point operator+ (const Point &lhs, const Point &rhs);
    friend Point operator- (const Point &lhs, const Point &rhs);
    friend double sqrDist(const Point &p1, const Point &p2);
    
public:
    Point();
    
    Point(int x, int y);
    
    // Will make use of implicit copy constructor and assignment operators
    // for shallow copy, which is fine since there is no dynamically
    // allocated memory.
    
    int getX() const;
    int getY() const;
    void set(int x, int y);
    
    // overloaded comparison operator, two points are equal
    // if both their elements are equal
    bool operator==(const Point &other);
    
private:
    int m_x, m_y;
};

#endif//POINT_H
