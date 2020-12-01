#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() { set(0, 0); }
    Point(int newX, int newY) { set(newX, newY); }
    Point(const Point& src) { set(src.x, src.y); }

    //Operations
    Point add(const Point& pt);
    Point sub(const Point& pt);
    Point operator+(const Point& pt) { return add(pt); }
    Point operator-(const Point& pt) { return sub(pt); }

    void set(int newX, int newY);
    int getX() const { return x; }
    int getY() const { return y; }
};

int main()
{
    Point point1(20, 20);
    Point point2(0, 5);
    Point point3(-10, 25);
    Point point4 = point1 + point2 + point3;

    std::cout << "The point is: " << point4.getX();
    cout << ", " << point4.getY() << ".";

    return 0;
}

void Point::set(int newX, int newY) {
    if (newX < 0)
        newX *= -1;
    if (newY < 0)
        newY *= -1;
    x = newX;
    y = newY;
}

Point Point::add(const Point& pt) {
    Point newPt;
    newPt.x = x + pt.x;
    newPt.y = y + pt.y;
    return newPt;
}

Point Point::sub(const Point& pt) {
    Point newPt;
    newPt.x = x - pt.x;
    newPt.y = y - pt.y;
    return newPt;
}
