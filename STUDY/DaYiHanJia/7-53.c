#include <stdio.h>
#include <math.h>
int sushu(int x);
int main(void)
{
    int n, k, i, j = 0, sum = 0;
    scanf("%d%d", &n, &k);
    for (i = n; i > 1; i--)
    {
        if (sushu(i))
        {
            j++;
            if (j == 1)
                printf("%d", i);
            else
                printf("+%d", i);
            sum += i;
            if (j == k)
                break;
        }
    }
    printf("=%d", sum);
    return 0;
}
int sushu(int x)
{
    int a = 1;
    if (x == 1 || x % 2 == 0 && x != 2)
        a = 0;
    else
    {
        for (int i = 3; i <= sqrt(x); i += 2)
        {
            if (x % i == 0)
            {
                a = 0;
                break;
            }
        }
    }
    return a;
}