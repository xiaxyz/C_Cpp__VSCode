#include <stdio.h>
int sushu(int x);
int main(void)
{
    int m, n, f = 0, sum = 0, i;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++)
    {
        if (sushu(i))
        {
            f++;
            sum += i;
        }
    }
    printf("%d %d", f, sum);
    return 0;
}
int sushu(int x)
{
    int i;
    for (i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    if (x == 1)
        return 0;
    return 1;
}