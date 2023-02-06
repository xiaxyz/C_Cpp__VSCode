#include <iostream>

using namespace std;

int main(void)
{
    string a[500], b[500];
    int i = 0, n = 0, f = 0;
    while (1)
    {
        cin >> a[i];
        if (a[i] == "0")
        {
            break;
        }
        for (int j = 0; j < n; ++j)
        {
            if (a[i] == b[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            b[n] = a[i];
            ++n;
        }
        else 
        {
            f = 0;
        }
        ++i;
    }
    for (int j = 0; j < n; ++j)
    {
        cout << b[j];
    }
    return 0;
}