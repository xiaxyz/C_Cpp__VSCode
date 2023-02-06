#include <stdio.h>
int main(void)
{
    int a[100][100], b[100][100], ra, ca, rb, cb, i, j, k;
    scanf("%d%d", &ra, &ca);
    for (i = 0; i < ra; i++)
    {
        for (j = 0; j < ca; j++)
            scanf("%d", &a[i][j]);
    }
    scanf("%d%d", &rb, &cb);
    for (i = 0; i < rb; i++)
    {
        for (j = 0; j < cb; j++)
            scanf("%d", &b[i][j]);
    }
    if (ca != rb)
        printf("Error: %d != %d", ca, rb);
    else
    {
        printf("%d %d\n", ra, cb);
        for (i = 0; i < ra; i++)
        {
            for (j = 0; j < cb; j++)
            {
                int sum;
                sum = 0;
                for (k = 0; k < ca; k++)
                    sum += a[i][k] * b[k][j];
                printf("%d", sum);
                if (j != (cb - 1))
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}