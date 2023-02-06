#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
public:
    void set_r(int r);
    float area();

private:
    int radius;
};

void Circle::set_r(int r)
{
    radius = r;
}

float Circle::area()
{
    return 3.141592 * (float)pow(radius, 2);
}

int main(void)
{
    Circle c;
    int r;
    cin >> r;
    c.set_r(r);
    cout << c.area();
    return 0;
}