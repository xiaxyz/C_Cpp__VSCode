#include <stdio.h>
int main(void)
{
    int n, m, a[100], i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
    {
        int temp;
        temp = a[0];
        for (int j = 0; j < n - 1; j++)
            a[j] = a[j + 1];
        a[n - 1] = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(" ");
    }
    return 0;
}