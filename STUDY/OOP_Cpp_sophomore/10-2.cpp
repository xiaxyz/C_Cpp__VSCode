#include <iostream>

using namespace std;

class Set
{
public:
    Set(int * = NULL, int = 0);
    Set(const Set &);
    ~Set();
    void print();
    Set &operator=(const Set &);
    friend Set operator+(const Set &, const Set &);
    friend Set operator-(const Set &, const Set &);
    friend Set operator*(const Set &, const Set &);

protected:
    int *num;
    int total;
};
Set::Set(int *a, int t)
{
    total = t;
    num = new int[total]();
    for (int i = 0; i < total; ++i)
    {
        num[i] = a[i];
    }
}
Set::Set(const Set &s)
{
    *this = s;
}
Set::~Set()
{
    delete[] num;
}
void Set::print()
{
    if (num == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    for (int i = 0; i < total; ++i)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}
Set &Set::operator=(const Set &s)
{
    total = s.total;
    num = new int[total]();
    for (int i = 0; i < total; ++i)
    {
        num[i] = s.num[i];
    }
    return *this;
}
Set operator+(const Set &a, const Set &b)
{
    Set x = a;
    int f = 0;
    int *t = new int[b.total](), t_n = 0;
    for (int i = 0; i < b.total; ++i)
    {
        for (int j = 0; j < a.total; ++j)
        {
            if (b.num[i] == a.num[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            t[t_n] = b.num[i];
            ++t_n;
        }
        f = 0;
    }
    int *num = new int[x.total + t_n];
    memcpy(num, x.num, x.total * sizeof(int));
    memcpy(num + x.total, t, t_n * sizeof(int));
    delete[] t;
    delete[] x.num;
    x.num = num;
    x.total += t_n;
    return x;
}
Set operator-(const Set &a, const Set &b)
{
    Set x;
    int f = 0;
    int *t = new int[a.total](), t_n = 0;
    for (int i = 0; i < a.total; ++i)
    {
        for (int j = 0; j < b.total; ++j)
        {
            if (a.num[i] == b.num[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            t[t_n] = a.num[i];
            ++t_n;
        }
        f = 0;
    }
    delete[] x.num;
    x.num = t;
    x.total = t_n;
    return x;
}
Set operator*(const Set &a, const Set &b)
{
    Set x;
    int *t = new int[a.total](), t_n = 0;
    for (int i = 0; i < a.total; ++i)
    {
        for (int j = 0; j < b.total; ++j)
        {
            if (a.num[i] == b.num[j])
            {
                t[t_n] = a.num[i];
                ++t_n;
            }
        }
    }
    delete[] x.num;
    x.num = t;
    x.total = t_n;
    return x;
}

int main(void)
{
    int x[3] = {1, 2, 3};
    int y[6] = {2, 5, 6, 7, 8, 9};
    Set a(x, 3);
    Set b(y, 6);
    Set c;
    cout << "a : ";
    a.print();
    cout << "b : ";
    b.print();
    c = a + b;
    cout << "a + b : ";
    c.print();
    c = a - b;
    cout << "a - b : ";
    c.print();
    return 0;
}
