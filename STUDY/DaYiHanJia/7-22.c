#include <stdio.h>
int chachong(int *b, int x, int n);
int main(void)
{
    int n[2], a[2][20], i, j, k = 0, b[40], f = 0;
    scanf("%d", &n[0]);
    for (i = 0; i < n[0]; i++)
        scanf("%d", &a[0][i]);
    scanf("%d", &n[1]);
    for (i = 0; i < n[1]; i++)
        scanf("%d", &a[1][i]);
    for (i = 0; i < n[0]; i++)
    {
        for (j = 0; j < n[1]; j++)
        {
            if (a[0][i] == a[1][j])
                f = 1;
        }
        if (f == 0)
        {
            if (chachong(b, a[0][i], k))
            {
                b[k] = a[0][i];
                k++;
            }
        }
        f = 0;
    }
    for (i = 0; i < n[1]; i++)
    {
        for (j = 0; j < n[0]; j++)
        {
            if (a[1][i] == a[0][j])
                f = 1;
        }
        if (f == 0)
        {
            if (chachong(b, a[1][i], k))
            {
                b[k] = a[1][i];
                k++;
            }
        }
        f = 0;
    }
    for (i = 0; i < k; i++)
    {
        printf("%d", b[i]);
        if (i != k - 1)
            printf("\040");
    }
    return 0;
}
int chachong(int *b, int x, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (b[i] == x)
            return 0;
    }
    return 1;
}