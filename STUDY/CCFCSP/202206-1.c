#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float average(int n, int *a);
float vari(float a_a, int n, int *a);

int main(void)
{
    int n, *a;
    scanf ("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) 
        scanf ("%d", a + i);
    float a_a, a_v;
    a_a = average(n, a);
    a_v = vari(a_a, n, a);
    float f;
    for (i = 0; i < n; i++) 
    {
        f = (*(a + i) - a_a) / pow (a_v, 0.5);
        printf ("%f\n", f);
    }
    return 0;
}

float average(int n, int *a)
{
    int i;
    float sum = 0;
    for (i = 0; i < n; i++)
        sum += *(a + i);
    return sum / n;
}

float vari(float a_a, int n, int *a)
{
    int i;
    float d = 0;
    for (i = 0; i < n; i++)
        d += pow(*(a + i) - a_a, 2);
    return d / n;
}