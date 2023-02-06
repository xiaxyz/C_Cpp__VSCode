#include <stdio.h>
int main(void)
{
    int T, a[10][10] = {0}, n, i, j, f[100] = {0}, k;
    scanf("%d", &T);
    for (k = 0; k < T; k++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                if (i > j && a[i][j] != 0)
                    f[k]++;
            }
        }
    }
    for (i = 0; i < T; i++)
    {
        if (f[i] == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}