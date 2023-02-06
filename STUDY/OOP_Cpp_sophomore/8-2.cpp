#include <iostream>

using namespace std;

class Circle 
{
public:
    Circle(int r = 0)
    {
        R = r;
    }
    float area()
    {
        return 3.14 * R * R;
    }
    float circumference()
    {
        return 2 * 3.14 * R;
    }
    ~Circle()
    {
    }
protected:
    int R;
};

class Sphere : public Circle 
{
public:
    Sphere(int r = 0);
    float area();
    float volume();
    ~Sphere();
};
Sphere::Sphere(int r) : Circle(r)
{
}
float Sphere::area()
{
    return 4 * 3.14 * R * R;
}
float Sphere::volume()
{
    return 1.0 * 3 / 4 * 3.14 * R * R * R;
}
Sphere::~Sphere()
{
}

class Column : public Circle 
{
public:
    Column(int r = 0, int h = 0);
    float area();
    float volume();
    ~Column();
protected:
    int H;
};
Column::Column(int r, int h) : Circle(r)
{
    H = h;
}
float Column::area()
{
    return 2 * Circle::area() + Circle::circumference() * H;
}
float Column::volume()
{
    return Circle::area() * H;
}
Column::~Column()
{
}

int main(void)
{
    Sphere a0(3);
    Column a1(2, 4);
    cout << "Sphere: " << "R = 3 " << "area = " << a0.area() << " " << "volume = " << a0.volume() << endl;
    cout << "Column: " << "R = 3 H = 4 " << "area = " << a1.area() << " " << "volume = " << a1.volume() << endl;
    return 0;
}