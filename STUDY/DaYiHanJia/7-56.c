#include <stdio.h>
int main(void)
{
    int n, k[100] = {0}, a[100][1000] = {0}, m, b[10000], i, j, c[100000], x = 0, f, y, z = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
        for (j = 0; j < k[i]; j++)
        {
            scanf("%d", &a[i][j]);
            if (k[i] != 1)
            {
                c[x] = a[i][j];
                x++;
            }
        }
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &y);
        f = 0;
        for (j = 0; j < x; j++)
        {
            if (y == c[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            int flag;
            flag = 0;
            for (int t = 0; t < z; t++)
            {
                if (y == b[t])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                b[z] = y;
                z++;
            }
        }
    }
    if (z != 0)
    {
        for (i = 0; i < z; i++)
        {
            printf("%05d", b[i]);
            if (i != z - 1)
                printf(" ");
        }
    }
    else
        printf("No one is handsome");
    return 0;
}