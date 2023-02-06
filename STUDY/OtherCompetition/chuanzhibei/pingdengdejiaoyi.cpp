#include <iostream>

using namespace std;

int dp(long long *a, long long n, long long m);

int main(void)
{
    long long n, *a, w, m;
    a = new long long[1000000];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> w;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            for (; i < n; ++i)
            {
                if(w >= a[i])
                {
                    m = a[i];
                    break;
                }
            }
        }
        else 
        {
            if (a[i] > m && a[i] <= w)
            {
                m = a[i];
            }
        }
    }
    cout << dp(a, n, m);
    return 0;
}

int dp(long long *a, long long n, long long m)
{
    int *x;
    x = new int[1000000000];
    x[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (j - a[i] >= 0)
            {
                x[j] = max(x[j - a[i]] + 1, x[j]);
            }
            else 
            {
                break;
            }
        }
    }
    return x[m];
}