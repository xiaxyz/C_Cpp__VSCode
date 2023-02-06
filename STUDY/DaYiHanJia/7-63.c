#include <stdio.h>
#include <math.h>
void huajian(long long *a, long long *b);
int main(void)
{
    long long a = 0, b = 1, c, d;
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &c, &d);
        a = a * d + c * b;
        b = b * d;
        if (b < 0)
        {
            a = -a;
            b = -b;
        }
        if (a != 0)
            huajian(&a, &b);
    }
    if (abs(a) >= b)
        if (a % b != 0)
            printf("%lld %lld/%lld", a / b, a % b, b);
        else
            printf("%lld", a / b);
    else if (a == 0)
        printf("0");
    else
        printf("%lld/%lld", a, b);
    return 0;
}
void huajian(long long *a, long long *b)
{
    long long c, d, e;
    c = abs(*a);
    d = abs(*b);
    if (c > d)
    {
        e = c;
        c = d;
        d = e;
    }
    while (1)
    {
        e = d % c;
        if (e == 0)
            break;
        else
        {
            d = c;
            c = e;
        }
    }
    *a /= c;
    *b /= c;
}