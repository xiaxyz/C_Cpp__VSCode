#include <stdio.h>
int main(void)
{
    int k, n, i, j, a[100] = {0}, m;
    scanf("%d%d", &n, &k);
    m = n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < k; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (a[j] < a[j - 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
        n--;
    }
    for (i = 0; i < m; i++)
    {
        printf("%d", a[i]);
        if (i < m - 1)
            printf(" ");
    }
    return 0;
}