#include <iostream>
#include <cmath>

using namespace std;

class num
{
public:
    friend class Complex;
    num(int a = 0, int b = 1, int c = 1);
    void judge_fu();
    num add(const num &x);
    num sub(const num &x);
    num mul(const num &x);
    num div(const num &x);
private:
    int zi, mu, fu;
};
num::num(int a, int b, int c)
{
    zi = a;
    mu = b;
    fu = c;
    judge_fu();
}
void num::judge_fu()
{
    if (zi >= 0)
    {
        if (mu < 0)
        {
            fu = -1;
            mu = -mu;
        }
        else
        {
            fu = 1;
        }
    }
    else
    {
        zi = -zi;
        if (mu < 0)
        {
            fu = 1;
            mu = -mu;
        }
        else
        {
            fu = -1;
        }
    }
}
num num::add(const num &x)
{
    num t;
    t.zi = fu * zi * x.mu + x.fu * mu * x.zi;
    t.mu = mu * x.mu;
    t.judge_fu();
    return t;
}
num num::sub(const num &x)
{
    num t;
    t.zi = fu * zi * x.mu - fu * mu * x.zi;
    t.mu = mu * x.mu;
    t.judge_fu();
    return t;
}
num num::mul(const num &x)
{
    num t;
    t.zi = fu * zi * x.fu * x.zi;
    t.mu = mu * x.mu;
    t.judge_fu();
    return t;
}
num num::div(const num &x)
{
    num t;
    t.zi = fu * zi * x.mu;
    t.mu = mu * x.fu * x.zi;
    t.judge_fu();
    return t;
}

class Complex
{
public:
    Complex(num a, num b);
    Complex(int a = 0, int b = 0);
    Complex c_add(Complex &x);
    Complex c_sub(Complex &x);
    Complex c_mul(Complex &x);
    Complex c_div(Complex &x);
    float mod();
    void print();
private:
    num shi, xu;
};
Complex::Complex(num a, num b)
{
    shi = a;
    xu = b;
}
Complex::Complex(int a, int b)
{
    shi.zi = a;
    xu.zi = b;
}
Complex Complex::c_add(Complex &x)
{
    Complex t;
    t.shi = shi.add(x.shi);
    t.xu = xu.add(x.xu);
    return t;
}
Complex Complex::c_sub(Complex &x)
{
    Complex t;
    t.shi = shi.sub(x.shi);
    t.xu = xu.sub(x.xu);
    return t;
}
Complex Complex::c_mul(Complex &x)
{
    Complex t;
    num ss, xx, sx, xs;
    ss = shi.mul(x.shi);
    xx = xu.mul(x.xu);
    sx = shi.mul(x.xu);
    xs = xu.mul(x.shi);
    t.shi = ss.sub(xx);
    t.xu = sx.add(xs);
    return t;
}
Complex Complex::c_div(Complex &x)
{
    Complex t;
    num ss, xx, sx, xs, s2, x2;
    ss = shi.mul(x.shi);
    xx = xu.mul(x.xu);
    sx = shi.mul(x.xu);
    xs = xu.mul(x.shi);
    s2 = x.shi.mul(x.shi);
    x2 = x.xu.mul(x.xu);
    t.shi = ss.add(xx).div(s2.add(x2));
    t.xu = xs.sub(sx).div(s2.add(x2));
    return t;
}
float Complex::mod()
{
    num t;
    t = shi.mul(shi).add(xu.mul(xu));
    return sqrt(t.zi) / sqrt(t.mu);
}
void Complex::print()
{
    if (shi.fu < 0)
    {
        cout << "-";
    }
    if (shi.mu != 1)
    {
        cout << "(" << shi.zi << "/" << shi.mu << ")";
    }
    else
    {
        cout << shi.zi;
    }
    if(xu.fu > 0)
    {
        if (xu.mu != 1)
        {
            cout << "+" << "(" << xu.zi << "/" << xu.mu << ")" << "i" << endl;
        }
        else
        {
            cout << "+" << xu.zi << "i" << endl;
        }
    }
    else
    {
        if (xu.mu != 1)
        {
            cout << "-" << "(" << xu.zi << "/" << xu.mu << ")" << "i" << endl;
        }
        else
        {
            cout << "-" << xu.zi << "i" << endl;
        }
    }
}

int main(void)
{
    Complex a(3, 4), b(2, 3);
    cout << "第一个数 ";
    a.print();
    cout << "第二个数 ";
    b.print();
    cout << "相加 ";
    a.c_add(b).print();
    cout << "相减 ";
    a.c_sub(b).print();
    cout << "相乘 ";
    a.c_mul(b).print();
    cout << "相除 ";
    a.c_div(b).print();
    cout << "第一个数模长 " << a.mod() << endl;
    cout << "第二个数模长 " << b.mod() << endl;
    return 0;
}
