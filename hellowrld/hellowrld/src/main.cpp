#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape {
public:
    virtual int getArea() = 0;
};

class Rect : public Shape {
public:
    Rect(int width = 1, int height = 1) { w = width, h = height; }
    int getArea() { return w * h; }
private:
    int w;
    int h;
};

class Circle : public Shape {
public:
    Circle(int radius = 1) { r = radius; }
    int getArea() { return (r * r) * pi; }
private:
    int r;
    int pi = 3;
};

class Triangle : public Shape {
public:
    Triangle(int width = 1, int height = 1) { w = width, h = height; }
    int getArea() { return (w * h) / 2; }
private:
    int w;
    int h;
};

int main() {

    Shape* rect1 = new Rect(4, 5);
    Shape* rect2 = new Rect(10, 10);

    Shape* circle1 = new Circle(10);
    Shape* circle2 = new Circle(33);

    Shape* triangle1 = new Triangle(10, 6);

    vector<Shape*> pointers = { rect1, rect2, circle1, circle2, triangle1 };

    for (int i = 0; i < pointers.size(); i++)
    {
        std::cout << pointers[i]->getArea() << "\n";
    }
}