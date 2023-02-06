#include <iostream>

using namespace std;

int judge(int h1, int h0, int m1, int m0);

int main(void)
{
    int h1 = 0, h0 = 0, m1 = 0, m0 = 0, x, y;
    cin >> x;
    y = x / 1440;
    x %= 1440;
    int n = 0;
    for (int i = 0; i < 1440; ++i)
    {
        ++m0;
        if (m0 == 10)
        {
            ++m1;
            m0 = 0;
        }
        if (m1 == 6)
        {
            ++h0;
            m1 = 0;
        }
        if (h0 == 10)
        {
            h1++;
            h0 = 0;
        }
        if (h1 == 2 && h0 == 4)
        {
            h1 = 0;
            h0 = 0;
        }
        n += judge(h1, h0 , m1, m0);
    }
    n *= y;
    ++n;
    for (int i = 0; i < x; ++i)
    {
        ++m0;
        if (m0 == 10)
        {
            ++m1;
            m0 = 0;
        }
        if (m1 == 6)
        {
            ++h0;
            m1 = 0;
        }
        if (h0 == 10)
        {
            h1++;
            h0 = 0;
        }
        if (h1 == 2 && h0 == 4)
        {
            h1 = 0;
            h0 = 0;
        }
        n += judge(h1, h0 , m1, m0);
    }
    cout << n;
    return 0;
}

int judge(int h1, int h0, int m1, int m0)
{
    if (h1 == 0 && h0 - m1 == m1 - m0)
    {
        return 1;
    }
    if (h1 != 0 && h1 - h0 == h0 - m1 && h0 - m1 == m1 - m0)
    {
        return 1;
    }
    return 0;
}