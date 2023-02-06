#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    string x, str;
    int n = 0;
    while (getline(cin, str))
    {
        x += str;
        x += '\n';
        ++n;
    }
    int m = 1;
    x.insert(0, " ");
    x.insert(0, to_string(m));
    for (int j = (int)log10(m) + 1; j < (int)log10(n) + 1; ++j)
    {
        x.insert(0, " ");
    }
    m++;
    for (int i = 0; i < x.length(); ++i)
    {
        if (x[i] == '\n' && i != x.length() - 1)
        {
            x.insert(i + 1, " ");
            x.insert(i + 1, to_string(m));
            for (int j = (int)log10(m) + 1; j < (int)log10(n) + 1; ++j)
            {
                x.insert(i + 1, " ");
            }
            m++;
        }
    }
    cout << x;
    return 0;
}