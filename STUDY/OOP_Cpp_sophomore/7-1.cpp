#include <iostream>

using namespace std;

class Point 
{
public:
    Point(int = 0, int = 0, int = 0);
    void setP(int = 0, int = 0, int = 0);
    void prin();
private:
    int X, Y, Z;
};
Point::Point(int x, int y, int z)
{
    setP(x, y, z);
}
void Point::setP(int x, int y, int z)
{
    X = x;
    Y = y;
    Z = z;
}
void Point::prin()
{
    cout << "点的坐标为:" << "(" << X << "," << Y << "," << Z << ")" << endl;
}

class Rectangle : public Point 
{
public:
    Rectangle(int = 0, int = 0, int x = 0, int y = 0, int z = 0);
    void setR(int = 0, int = 0);
    int area();
    void prin();
private:
    int length, width;
};
Rectangle::Rectangle(int l, int w, int x, int y, int z) : Point(x, y, z)
{
    setR(l, w);
}
void Rectangle::setR(int l, int w)
{
    length = l;
    width = w;
}
int Rectangle::area()
{
    return length * width;
}
void Rectangle::prin()
{
    Point::prin();
    cout << "长为:" << length << endl;
    cout << "宽为:" << width << endl;
}

class Cuboid : public Point 
{
public:
    Cuboid(int = 0, int = 0, int = 0, int x = 0, int y = 0, int z = 0);
    void setC(int = 0, int = 0, int = 0);
    int volume();
    void prin();
private:
    int length, width, height;
};
Cuboid::Cuboid(int l, int w, int h, int x, int y, int z) : Point(x, y, z)
{
    setC(l, w, h);
}
void Cuboid::setC(int l, int w, int h)
{
    length = l;
    width = w;
    height = h;
}
int Cuboid::volume()
{
    return length * width * height;
}
void Cuboid::prin()
{
    Point::prin();
    cout << "长为:" << length << endl;
    cout << "宽为:" << width << endl;
    cout << "高为:" << height << endl;
}

int main(void) 
{
    Rectangle a(2, 3, 1, 1, 1);
    Cuboid b(4, 5, 6, 2, 2, 2);
    a.prin();
    cout << "长方形面积为:" << a.area() << endl;
    b.prin();
    cout << "长方体体积为:" << b.volume() << endl;
    return 0;
}