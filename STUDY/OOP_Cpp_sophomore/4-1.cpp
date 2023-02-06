#include <iostream>
using namespace std;

class num
{
public:
    num(int x = 0, int y = 1);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void prin();
    void simp();
    void change(int &a, int &b);
private:
    int X;
    int Y;
};

num::num(int x, int y)
{
    X = x;
    Y = y;
}
int num::getX()
{
    return X;
}
int num::getY()
{
    return Y;
}
void num::setX(int x)
{
    X = x;
}
void num::setY(int y)
{
    Y = y;
}
void num::prin()
{
    cout << X << '/' << Y;
}
void num::simp()
{
    int a = X, b = Y;
    change(a, b);
    while(a % b != 0)
    {
        a = a % b;
        change(a, b);
    }
    if(b < 0)
    {
        b = -b;
    }
    X /= b;
    Y /= b;
}
void num::change(int &a, int &b)
{
    if(a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
}

num add(num a, num b);
num sub(num a, num b);
num mul(num a, num b);
num div(num a, num b);

int main(void)
{
    int a, b;
    cout << "请以\"分子 分母\"的方式输入第一个数 如\"1 2\"" << endl;
    cin >> a >> b;
    num x(a, b);
    cout << "请输入第二个数" << endl;
    cin >> a >> b;
    num y(a, b);
    cout << "add ";
    add(x, y).prin();
    cout << endl;
    cout << "sub ";
    sub(x, y).prin();
    cout << endl;
    cout << "mul ";
    mul(x, y).prin();
    cout << endl;
    cout << "div ";
    div(x, y).prin();
    cout << endl;
    return 0;
}

num add(num a, num b)
{
    num c;
    c.setX(a.getX() * b.getY() + a.getY() * b.getX());
    c.setY(a.getY() * b.getY());
    c.simp();
    return c;
}
num sub(num a, num b)
{
    num c;
    c.setX(a.getX() * b.getY() - a.getY() * b.getX());
    c.setY(a.getY() * b.getY());
    c.simp();
    return c;
}
num mul(num a, num b)
{
    num c;
    c.setX(a.getX() * b.getX());
    c.setY(a.getY() * b.getY());
    c.simp();
    return c;
}
num div(num a, num b)
{
    num c;
    c.setX(a.getX() * b.getY());
    c.setY(a.getY() * b.getX());
    c.simp();
    return c;
}
