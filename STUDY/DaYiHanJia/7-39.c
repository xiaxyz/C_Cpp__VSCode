#include <stdio.h>
int main(void)
{
    int a, b, i, j, sum = 0, f = 0;
    scanf("%d%d", &a, &b);
    for (i = a; i <= b; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
                sum += j;
        }
        if (sum == i)
        {
            printf("%d = 1", sum);
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                    printf(" + %d", j);
            }
            printf("\n");
            f++;
        }
        sum = 0;
    }
    if (f == 0)
        printf("None");
    return 0;
}