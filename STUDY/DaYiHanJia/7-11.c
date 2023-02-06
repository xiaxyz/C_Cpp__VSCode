#include <stdio.h>
int main(void)
{
    float x, cost = 10;
    int t;
    scanf("%f%d", &x, &t);
    if (x <= 3)
        ;
    else if (x > 3 && x <= 10)
    {
        cost += 2 * (x - 3);
    }
    else
    {
        cost += 14 + (x - 10) * 3;
    }
    if (t >= 5)
    {
        cost += t / 5 * 2;
    }
    printf("%.f", cost);
    return 0;
}