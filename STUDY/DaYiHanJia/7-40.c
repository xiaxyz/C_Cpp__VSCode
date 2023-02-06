#include <stdio.h>
int main(void)
{
    int n, a[10] = {0}, x, f = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= x && a[i + 1] >= x)
        {
            f++;
            for (int j = n; j > i + 1; j--)
                a[j] = a[j - 1];
            a[i + 1] = x;
            break;
        }
    }
    if (f == 0)
    {
        if (x <= a[0])
        {
            for (int j = n; j > 0; j--)
                a[j] = a[j - 1];
            a[0] = x;
        }
        else
            a[n] = x;
    }
    for (int i = 0; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}