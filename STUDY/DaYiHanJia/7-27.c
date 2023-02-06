#include <stdio.h>
int main(void)
{
    int a[6][6], n, i, j, max[6] = {0}, min[6], f = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0)
                max[i] = a[i][j];
            else
            {
                if (max[i] < a[i][j])
                    max[i] = a[i][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0)
                min[i] = a[j][i];
            else
            {
                if (min[i] > a[j][i])
                    min[i] = a[j][i];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (max[j] == min[i])
            {
                f++;
                printf("%d %d", j, i);
            }
        }
    }
    if (f == 0)
        printf("NONE");
    return 0;
}