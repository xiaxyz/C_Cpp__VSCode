#include <stdio.h>
#include <math.h>
int sushu(int x);
int main(void)
{
    int N, a, b, i;
    scanf("%d", &N);
    for (i = 1; i < N; i++)
    {
        if (sushu(i))
        {
            if (sushu(N - i))
            {
                printf("%d = %d + %d", N, i, N - i);
                break;
            }
        }
    }
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