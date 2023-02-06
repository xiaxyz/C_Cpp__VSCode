#include <stdio.h>
int main(void)
{
    int m, n, a[6][6] = {0}, i, j, sum[6] = {0};
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
    for (i = 0; i < m; i++)
        printf("%d\n", sum[i]);
    return 0;
}