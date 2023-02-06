#include <iostream>
#define N 100000

using namespace std;

int main(void)
{
    int n, k;
    int f = 0;
    cin >> n >> k;
    int a[N] = {1};
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        if (a[y] == 0)
            f++;
        a[x] = 1;
    }
    cout << f;
    return 0;
}