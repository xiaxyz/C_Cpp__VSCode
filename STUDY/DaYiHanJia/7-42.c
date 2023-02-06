#include <stdio.h>
int main(void)
{
    int n, a[10] = {0}, i, max, min;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 0)
        {
            max = a[i];
            min = a[i];
        }
        else
        {
            if (max < a[i])
                max = a[i];
            if (min > a[i])
                min = a[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            int temp;
            temp = a[0];
            a[0] = min;
            a[i] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            int temp;
            temp = a[n - 1];
            a[n - 1] = max;
            a[i] = temp;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}