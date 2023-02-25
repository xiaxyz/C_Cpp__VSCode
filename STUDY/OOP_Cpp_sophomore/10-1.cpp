#include <iostream>
#include <algorithm>

using namespace std;

class num
{
public:
    num(int = 0, int = 1);
    num(string);
    void judge_s();
    num StoN(string = "0");
    void simplify();
    void print();
    friend num operator+(num &, num &);
    friend num operator-(num &, num &);
    friend num operator*(num &, num &);
    friend num operator/(num &, num &);
    friend bool operator==(num &, num &);
    friend bool operator>(num &, num &);
    friend bool operator<(num &, num &);

protected:
    int symbol;
    int numerator;
    int denominator;
};
num::num(int n, int d)
{
    numerator = n;
    denominator = d;
    judge_s();
}
num::num(string x)
{
    num t = StoN(x);
    symbol = t.symbol;
    numerator = t.numerator;
    denominator = t.denominator;
}
void num::judge_s()
{
    if ((numerator >= 0 && denominator > 0) || (numerator <= 0 && denominator < 0))
    {
        symbol = 1;
    }
    else
    {
        symbol = -1;
    }
    numerator = abs(numerator);
    denominator = abs(denominator);
}
num num::StoN(string x)
{
    string n, d;
    if (x.find("/") == string::npos)
    {
        d = "1";
        n = x;
    }
    else
    {
        n = x.substr(0, x.find("/"));
        d = x.substr(x.find("/") + 1);
    }
    num t(stoi(n), stoi(d));
    return t;
}
void num::simplify()
{
    int a[2] = {numerator, denominator};
    sort(a, a + 2, greater<int>());
    while (a[0] % a[1] != 0)
    {
        a[0] %= a[1];
        sort(a, a + 2, greater<int>());
    }
    numerator /= a[1];
    denominator /= a[1];
}
void num::print()
{
    if (symbol == -1)
    {
        cout << "-";
    }
    cout << numerator << "/" << denominator;
}

num operator+(num &a, num &b)
{
    num x;
    x.denominator = a.denominator * b.denominator;
    x.numerator = a.symbol * a.numerator * b.denominator + b.symbol * b.numerator * a.denominator;
    x.judge_s();
    x.simplify();
    return x;
}
num operator-(num &a, num &b)
{
    num x;
    x.denominator = a.denominator * b.denominator;
    x.numerator = a.symbol * a.numerator * b.denominator - b.symbol * b.numerator * a.denominator;
    x.judge_s();
    x.simplify();
    return x;
}
num operator*(num &a, num &b)
{
    num x;
    x.denominator = a.denominator * b.denominator;
    x.numerator = a.symbol * a.numerator * b.symbol * b.numerator;
    x.judge_s();
    x.simplify();
    return x;
}
num operator/(num &a, num &b)
{
    num x;
    x.denominator = a.denominator * b.symbol * b.numerator;
    x.numerator = a.symbol * a.numerator * b.denominator;
    x.judge_s();
    x.simplify();
    return x;
}
bool operator==(num &a, num &b)
{
    num c = a;
    num d = b;
    c.judge_s();
    c.simplify();
    d.judge_s();
    d.simplify();
    if (c.symbol == d.symbol && c.numerator == d.numerator && c.denominator == d.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(num &a, num &b)
{
    num t = a - b;
    if (t.symbol == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<(num &a, num &b)
{
    num t = a - b;
    if (t.symbol == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    num a("-1/2");
    num b("3");
    num c;
    cout << "a : ";
    a.print();
    cout << endl;
    cout << "b : ";
    b.print();
    cout << endl;
    c = a + b;
    cout << "a + b : ";
    c.print();
    cout << endl;
    c = a - b;
    cout << "a - b : ";
    c.print();
    cout << endl;
    c = a * b;
    cout << "a * b : ";
    c.print();
    cout << endl;
    c = a / b;
    cout << "a / b : ";
    c.print();
    cout << endl;
    cout << "(a < b ? < : >=) ";
    if (a < b)
    {
        cout << "<";
    }
    else
    {
        cout << ">=";
    }
    return 0;
}
