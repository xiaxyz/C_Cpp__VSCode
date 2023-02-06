#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    double i, sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum += pow(2, i);
    printf("result = %.0lf", sum);
    return 0;
}