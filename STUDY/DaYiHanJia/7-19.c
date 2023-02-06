#include <stdio.h>
int main(void)
{
    int n, a[10][10], sum = 0, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (n - 1 - i != j && i != n - 1 && j != n - 1)
                sum += a[i][j];
        }
    }
    printf("%d", sum);
    return 0;
}