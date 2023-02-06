#include <iostream>

using namespace std;

class Circle 
{
public:
    Circle(float = 0);
    virtual float area();
    virtual float volume() = 0;
protected:
    float R;
};
Circle::Circle(float r)
{
    R = r;
}
float Circle::area()
{
    return 3.14 * R * R;
}

class Sphere : public Circle 
{
public:
    Sphere(float = 0);
    float area();
    float volume();
};
Sphere::Sphere(float r) : Circle(r)
{
}
float Sphere::area()
{
    return 4 * 3.14 * R * R;
}
float Sphere::volume()
{
    return 3.14 * 3 / 4 * R * R * R;
}

class Column : public Circle 
{
public:
    Column(float = 0, float = 0);
    float area();
    float volume();
protected:
    float H;
};
Column::Column(float r, float h) : Circle(r)
{
    H = h;
}
float Column::area()
{
    return Circle::area() * 2 + 2 * 3.14 * R * H;
}
float Column::volume()
{
    return Circle::area() * H;
}

int main(void)
{
    Circle *a = new Sphere(3);
    cout << a->volume();
    return 0;
}