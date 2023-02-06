#include <iostream>
#define N 100000

using namespace std;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    int t[N] = {0}, c[N] = {0};
    for (int i = 0; i < n; i++)
        cin >> t[i] >> c[i];
    int q[N] = {0};
    for (int i = 0; i < m; i++)
        cin >> q[i];
    int f;
    for (int i = 0; i < m; i++)
    {
        f = 0;
        for (int j = 0; j < n; j++)
        {
            if (q[i] + k <= t[j] && q[i] + k + c[j] - 1 >= t[j])
                f++;
        }
        cout << f << endl;
    }
    return 0;
}