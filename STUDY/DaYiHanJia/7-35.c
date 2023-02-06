#include <stdio.h>
double fact(int n);
double fenmu(int n);
int main(void)
{
    double eps, last = 1, sum = 1;
    int i;
    scanf("%le", &eps);
    for (i = 1; last > eps; i++)
    {
        last *= 1.0 * i / (2 * i + 1);
        sum += last;
    }
    printf("PI = %.5lf", 2 * sum);
    return 0;
}