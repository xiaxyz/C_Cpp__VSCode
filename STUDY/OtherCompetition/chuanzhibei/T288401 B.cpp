#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int max_0 = max(n, m);
    int *a = new int[max_0]();
    for (int i = n - 1; i >= 0; --i)
    {
        cin >> a[i];
    }
    int *b = new int[max_0]();
    for (int i = m - 1; i >= 0; --i)
    {
        cin >> b[i];
    }
    int *x = new int[max_0 + 1]();
    for (int i = 0; i < max_0; ++i)
    {
        int c;
        c = a[i] + b[i];
        x[i] = c % (i + 2);
        a[i + 1] += c / (i + 2);
    }
    if (x[max_0] != 0)
    {
        cout << x[max_0] << " ";
    }
    for (int i = max_0 - 1; i >= 0; --i)
    {
        cout << x[i];
        if (i != 0)
        {
            cout << " ";
        }
    }
    return 0;
}