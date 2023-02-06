#include <stdio.h>
#include <malloc.h>
int main(void)
{
    int n, *p, i;
    float max, min, average, sum = 0;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {

        scanf("%d", p + i);
        if (i == 0)
        {
            max = *(p + i);
            min = *(p + i);
        }
        else
        {
            if (max < *(p + i))
                max = *(p + i);
            if (min > *(p + i))
                min = *(p + i);
        }
        sum += *(p + i);
    }
    average = sum / n;
    printf("average = %.2f\nmax = %.2f\nmin = %.2f", average, max, min);
    return 0;
}